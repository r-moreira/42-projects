#include "../includes/webserv.h"
#include "../includes/parser/HttpRequestParser.h"

/*
 * * AF_INET is the IP address family of the server
 * * SOCK_STREAM is the type of TCP socket
 * * IPPROTO_TCP is the protocol of the socket
 * * INADDR_ANY accepts any IP address
 * * SOMAXCONN is the maximum number of connections that can be queued
 */
int create_server_socket(int port) {
    struct sockaddr_in sevr_addr = {};
    sevr_addr.sin_family = AF_INET;
    sevr_addr.sin_port = htons(port);
    sevr_addr.sin_addr.s_addr = INADDR_ANY;

    int server_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (server_fd < 0) {
        std::cerr << RED << "Error while opening server_fd: " << strerror(errno) << RESET << std::endl;
        exit(EXIT_FAILURE);
    }

    if (bind(server_fd, (struct sockaddr *) &sevr_addr, sizeof(sevr_addr)) != 0) {
        std::cerr << RED << "Error while binding server_fd to address: " << strerror(errno) << RESET << std::endl;
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, SOMAXCONN) < 0) {
        std::cerr << RED << "Error while listening on server_fd: " << strerror(errno) << RESET << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << GREEN << "Server started to listen at port: " << port << RESET << std::endl;
    return server_fd;
}

void set_non_blocking(int fd) {
    int flags = fcntl(fd, F_GETFL, 0);
    if (flags == -1) {
        std::cerr << RED << "Error while getting flags: " << strerror(errno) << RESET << std::endl;
        exit(EXIT_FAILURE);
    }
    flags |= O_NONBLOCK;
    if (fcntl(fd, F_SETFL, flags) == -1) {
        std::cerr << RED << "Error while setting flags: " << strerror(errno) << RESET << std::endl;
        exit(EXIT_FAILURE);
    }
}

void write_response(event_data_t *event_data) {

    std::string response;

    if (event_data->read_left == 2) {
        response = "HTTP/1.1 200 OK\r\nContent-Length: 20\r\n\r\nHello World!";
    } else {
        response = "\nWrite 2";
    }

    if (send(event_data->client_fd, response.c_str(), response.length(), 0) < 0) {
        std::cerr << RED << "Error while writing to client: " << strerror(errno) << RESET << std::endl;
    }
    std::cout << YELLOW << "Response sent to client" << RESET << std::endl;
    std::cout << BLUE << "Response: " << response << RESET << std::endl;

    event_data->read_left--; //Exemplo de controle para saber quando terminar a escrita

    if (event_data->read_left == 0) {
        event_data->event_status = Ended;
    }
}

void parse_request(event_data_t *event_data) {

    std::cout << MAGENTA << "Request Data:\n " << event_data->read_buffer << RESET << std::endl;

    const char *buffer = event_data->read_buffer.c_str();

    Request request;
    HttpRequestParser parser;

    HttpRequestParser::ParseResult result = parser.parse(request, buffer, buffer + strlen(buffer));

    if (result == HttpRequestParser::ParsingCompleted) {
        std::cout << "Parsed Request:\n" << request.inspect() << std::endl;
    } else {
        std::cerr << "Parsing failed" << std::endl;
        //Return error page
    }
    event_data->event_status = Writing;
}

void read_request(event_data_t *event_data) {
    int client_fd = event_data->client_fd;
    char buffer[READ_BUFFER_SIZE] = {};

    long bytes_read = read(client_fd, buffer, READ_BUFFER_SIZE);

    if (bytes_read == -1) {
        std::cerr << RED << "Error while reading from client: " << strerror(errno) << RESET << std::endl;
    }

    event_data->read_bytes += bytes_read;
    event_data->read_buffer.append(buffer);

    std::cout << YELLOW << "Read " << event_data->read_bytes << " bytes from client" << RESET << std::endl;
    std::cout << GREEN << "HTTP Request:\n" << buffer << RESET << std::endl;

    if (buffer[READ_BUFFER_SIZE - 1] == 0) {
        parse_request(event_data);
    }
}

void process_event(event_data_t *event_data) {

    if (event_data->event_status == Reading) {
        read_request(event_data);
    } else if (event_data->event_status == Writing) {
        write_response(event_data);
    }
}

void io_multiplexing_event_loop(int server_socket_fd) {
    int epoll_fd = epoll_create1(0);
    if (epoll_fd == -1) {
        std::cerr << RED << "Error while creating epoll fd: " << strerror(errno) << RESET << std::endl;
        exit(EXIT_FAILURE);
    }

    struct epoll_event server_event = {};
    struct epoll_event request_event = {};

    server_event.events = EPOLLIN | EPOLLET;
    server_event.data.fd = server_socket_fd;

    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, server_socket_fd, &server_event) == -1) {
        std::cerr << RED << "Error while adding socket to epoll: " << strerror(errno) << RESET << std::endl;
        exit(EXIT_FAILURE);
    }

    struct epoll_event epoll_events[MAX_EPOLL_EVENTS];
    while (1) {
        int nfds = epoll_wait(epoll_fd, epoll_events, MAX_EPOLL_EVENTS, -1);
        if (nfds == -1) {
            std::cerr << RED << "Error while waiting for epoll events: " << strerror(errno) << RESET << std::endl;
            continue;
        }

        for (int i = 0; i < nfds; i++) {
            if (epoll_events[i].data.fd == server_socket_fd) {
                struct sockaddr_in client_addr = {};
                socklen_t client_addr_len = sizeof(client_addr);

                int client_fd = accept(server_socket_fd, (struct sockaddr *) &client_addr, &client_addr_len);

                if (client_fd < 0) {
                    if (errno == EAGAIN || errno == EWOULDBLOCK) {
                        break;
                    } else {
                        std::cerr << RED << "Error while accepting client: " << strerror(errno) << RESET << std::endl;
                        break;
                    }
                }

                set_non_blocking(client_fd);

                event_data_t *event_data = new event_data_t;
                event_data->header = "";
                event_data->client_fd = client_fd;
                event_data->read_bytes = 0;
                event_data->event_status = Reading;
                event_data->read_left = 2; //TEMPORÁRIO

                request_event.data.ptr = event_data;
                request_event.events = EPOLLIN;

                if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, client_fd, &request_event) == -1) {
                    std::cerr << RED << "Error while adding client to epoll: " << strerror(errno) << RESET << std::endl;
                    continue;
                }
            } else {
                event_data_t *event_data = (event_data_t *) epoll_events[i].data.ptr;
                process_event(event_data);
                switch (event_data->event_status) {
                    case Reading:
                        request_event.events = EPOLLIN;
                        request_event.data.ptr = event_data;
                        if (epoll_ctl(epoll_fd, EPOLL_CTL_MOD, event_data->client_fd, &request_event) < 0) {
                            std::cerr << RED << "Error while adding reading event to epoll: " << strerror(errno)
                                      << RESET << std::endl;
                            continue;
                        }
                        break;
                    case Writing:
                        request_event.events = EPOLLOUT;
                        request_event.data.ptr = event_data;
                        if (epoll_ctl(epoll_fd, EPOLL_CTL_MOD, event_data->client_fd, &request_event) < 0) {
                            std::cerr << RED << "Error while adding writing event to epoll: " << strerror(errno)
                                      << RESET << std::endl;
                            continue;
                        }
                        break;
                    case Ended:
                        if (event_data->file != NULL) {
                            fclose(event_data->file);
                            event_data->file = NULL;
                        }
                        close(event_data->client_fd);
                        delete event_data;
                }

            }
        }
    }
}

int main(int argc, char **argv, char **env) {
    signal(SIGPIPE, SIG_IGN);

    if (argc != 2) {
        std::cout << CYAN << "Usage :  ./webserv {PATH TO CONFIGURATION FILE}" << RESET << std::endl;
        return EXIT_FAILURE;
    }

    srand(time(NULL));
    int server_socket_fd = create_server_socket(8080 + (rand() % 10));
    set_non_blocking(server_socket_fd);
    io_multiplexing_event_loop(server_socket_fd);

    return EXIT_SUCCESS;
}