#include "../includes/webserv.h"


#define client_message_SIZE 1024

using namespace std;

typedef enum {
    HTTP_HEADER,
    BAD_REQUEST,
    NOT_FOUND
} messageType;

string fileExtension[] = {
        "aac", "avi", "bmp", "css", "gif", "ico", "js",
        "json", "mp3", "mp4", "otf", "png", "php", "rtf",
        "svg", "txt", "webm", "webp", "woff", "woff", "zip",
        "html", "htm", "jpeg", "jpg",
};

string ContentType[] = {
        "Content-Type: audio/aac\r\n\r\n",
        "Content-Type: video/x-msvideo\r\n\r\n",
        "Content-Type: image/bmp\r\n\r\n",
        "Content-Type: text/css\r\n\r\n",
        "Content-Type: image/gif\r\n\r\n",
        "Content-Type: image/vnd.microsoft.icon\r\n\r\n",
        "Content-Type: text/javascript\r\n\r\n",
        "Content-Type: application/json\r\n\r\n",
        "Content-Type: audio/mpeg\r\n\r\n",
        "Content-Type: video/mp4\r\n\r\n",
        "Content-Type: font/otf\r\n\r\n",
        "Content-Type: image/png\r\n\r\n",
        "Content-Type: application/x-httpd-php\r\n\r\n",
        "Content-Type: application/rtf\r\n\r\n",
        "Content-Type: image/svg+xml\r\n\r\n",
        "Content-Type: text/plain\r\n\r\n",
        "Content-Type: video/webm\r\n\r\n",
        "Content-Type: video/webp\r\n\r\n",
        "Content-Type: font/woff\r\n\r\n",
        "Content-Type: font/woff2\r\n\r\n",
        "Content-Type: application/zip\r\n\r\n",
        "Content-Type: text/html\r\n\r\n",
        "Content-Type: text/html\r\n\r\n",
        "Content-Type: image/jpeg\r\n\r\n",
        "Content-Type: image/jpeg\r\n\r\n",
};

string Messages[] = {
        "HTTP/1.1 200 Ok\r\n ",
        "HTTP/1.0 400 Bad Request\r\nContent-Type: text/html\r\n\r\n<!doctype html><html><body>System is busy right now.</body></html>",
        "HTTP/1.0 404 File not found\r\nContent-Type: text/html\r\n\r\n<!doctype html><html><body>The reuested file does not exist on this server</body></html>"
};

std::vector<std::string> serverData;

int stoi(std::string s) {
    int multiplier = 1, result = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        result += multiplier * (s[i] - '0');
        multiplier *= 10;
    }
    return result;
}

string getStr(string sql, char end) {
    int counter = 0;
    string retStr = "";
    while (sql[counter] != '\0') {
        if (sql[counter] == end) { break; }
        retStr += sql[counter];
        counter++;
    }
    return (retStr);
}

void send_message(int fd, string filePath, string headerFile) {
    printf("Enter send_message\n");
    string header = Messages[HTTP_HEADER] + headerFile;
    filePath = "./public" + filePath;
    struct stat stat_buf; // hold information about our file to send

    printf("Before write\n");
    if (write(fd, header.c_str(), header.length()) < 0) {
        printf("cannot write to socket\n");
        return;
    }
    printf("After write\n");
    int fdimg = open(filePath.c_str(), O_RDONLY);

    if (fdimg < 0) {
        printf("cannot open file path: %s\n", filePath.c_str());
        return;
    }

    fstat(fdimg, &stat_buf);
    int img_total_size = stat_buf.st_size;
    int block_size = stat_buf.st_blksize;

    if (fdimg >= 0) {
        size_t sent_size;
        while (img_total_size > 0) {
            int send_bytes = ((img_total_size < block_size) ? img_total_size : block_size);
            int done_bytes = sendfile(fd, fdimg, NULL, send_bytes);
            img_total_size = img_total_size - done_bytes;
        }
        if (sent_size >= 0) {
            printf("sent file: %s\n", filePath.c_str());
        }
        close(fdimg);
    }

}

string findFileExt(string fileEx) {
    for (int i = 0; i <= sizeof(fileExtension); i++) {
        if (fileExtension[i] == fileEx) {
            return ContentType[i];
        }
    }
    printf("serving .%s as html\n", fileEx.c_str());
    return ("Content-Type: text/html\r\n\r\n");
}

void getData(string requestType, string client_message) {
    printf("GET DATA CALLED");

    string extract;
    string data = client_message;

    if (requestType == "GET") {
        data.erase(0, getStr(data, ' ').length() + 1);
        data = getStr(data, ' ');
        data.erase(0, getStr(data, '?').length() + 1);
    } else if (requestType == "POST") {
        int counter = data.length() - 1;
        while (counter > 0) {
            if (data[counter] == ' ' || data[counter] == '\n') { break; }
            counter--;
        }
        data.erase(0, counter + 1);
        int found = data.find("=");
        if (found == string::npos) { data = ""; }
    }

    int found = client_message.find("cookie");
    if (found != string::npos) {
        client_message.erase(0, found + 8);
        client_message = getStr(client_message, ' ');
        data = data + "&" + getStr(client_message, '\n');
    }
    while (data.length() > 0) {
        extract = getStr(data, '&');
        serverData.push_back(extract);
        data.erase(0, getStr(data, '&').length() + 1);
    }

    printf("GET DATA FINISHED");
}

int requestHandler(const string& client_message, int newSock) {
    string message = client_message;

    printf("client message: %s\n", client_message.c_str());
    string requestType = getStr(message, ' ');
    message.erase(0, requestType.length() + 1);
    string requestFile = getStr(message, ' ');

    string requestF = requestFile;
    string fileExt = requestF.erase(0, getStr(requestF, '.').length() + 1);
    string fileEx = getStr(getStr(fileExt, '/'), '?');
    requestFile = getStr(requestFile, '.') + "." + fileEx;

    if (requestType == "GET" || requestType == "POST") {
        if (requestFile.length() <= 1) {
            requestFile = "/index.html";
        }
        if (fileEx == "php") {
            //do nothing
            getData(requestType, client_message);
        }
        printf("Before send_message\n");
        send_message(newSock, requestFile, findFileExt(fileEx));
        printf("After send_message\n");
    }

    return 0;
}

int main(int argc, char **argv, char **env) {
    signal(SIGPIPE, SIG_IGN);

    if (argc != 2) {
        std::cout << "Usage :  ./webserv {PATH TO CONFIGURATION FILE}" << std::endl;
        return (EXIT_FAILURE);
    }

    int sockfd = -1, ret = -1, sessfd = -1, len = -1;
    char rbuff[client_message_SIZE];
    fd_set rfds;
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return EXIT_FAILURE;
    }
    printf("Socket created successfully\n");

    srand(time(NULL));
    int randomPORT = 8080 + (rand() % 10);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(randomPORT);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    ret = bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    if (ret < 0) {
        perror("ERROR on binding");
        close(sockfd);
        return EXIT_FAILURE;
    }
    printf("Bind successful %s:%d\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));

    ret = listen(sockfd, 15);
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

    struct timeval vl;
    vl.tv_sec = 3;
    vl.tv_usec = 0;

    while (1) {
        iset = rfds;
        ret = select(maxfd + 1, &iset, NULL, NULL, &vl);
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

                            requestHandler(rbuff, i);
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
