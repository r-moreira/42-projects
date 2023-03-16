
#include "../includes/webserv.h"

int main(int argc, char **argv, char **env) {
    signal(SIGPIPE, SIG_IGN);

    if (argc != 2) {
        std::cout << "Usage :  ./webserv {PATH TO CONFIGURATION FILE}" << std::endl;
        return (EXIT_FAILURE);
    }

    int sockfd = -1, ret = -1, sessfd = -1, len = -1;
    char rbuff[20];
    fd_set rfds;
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return EXIT_FAILURE;
    }
    printf("Socket created successfully\n");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    ret = bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    if (ret < 0) {
        perror("ERROR on binding");
        close(sockfd);
        return EXIT_FAILURE;
    }
    printf("Bind successful %s:%d\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));

    ret = listen(sockfd, 5);
    if (ret < 0) {
        perror("ERROR on listen");
        close(sockfd);
        return EXIT_FAILURE;
    }
    printf("Server listening for new connections\n............................\n");

    FD_ZERO(&rfds);
    FD_SET(sockfd, &rfds);
    int maxfd = sockfd;
    fd_set iset;
    while (1) {
        iset = rfds;
        ret = select(maxfd + 1, &iset, NULL, NULL, NULL);
        if (ret < 0) {
            perror("ERROR on select");
            continue;
        } else if (ret > 0) {
            if (FD_ISSET(sockfd, &iset) == 1) {
                printf("SELECT:: New connection request\n");

                sessfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &cli_addr);
                if (sessfd < 0) {
                    perror("ERROR on accept");
                    continue;
                }
                printf("Client request accepted from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

                FD_SET(sessfd, &rfds);
                printf("SELECT:: New sessionfd or read fd is added to the rfds\n");
                FD_CLR(sockfd, &iset);
                printf("SELECT:: sockfd is removed from the iset\n");
                if (maxfd < sessfd)
                    maxfd = sessfd;
            } else {
                for (int i = 0; i < maxfd + 1; i++) {
                    if (FD_ISSET(i, &iset) == 1) {
                        ret = read(i, rbuff, sizeof(rbuff));

                        if (ret < 0) {
                            perror("SELECT:: ERROR on read");
                            continue;
                        } else if (ret == 0) {
                            printf("SELECT:: Client %d session closed\n", i);
                            close(i);
                            FD_CLR(i, &rfds);
                        } else {
                            printf("SELECT:: Data available on fd %d\n", i);
                            printf("SELECT:: Data from client: %s\n", rbuff);
                            write(i, rbuff, strlen(rbuff) + 1);
                            printf("SELECT:: Data sent to client: %s\n", rbuff);
                        }
                    }
                }
            }
        } else if (ret == 0) {
            continue;
        }

    }   // end of while(1)

    close(sockfd);
    return EXIT_SUCCESS;
}
