#include "network.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>


int vladutz_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

int vladutz_bind(int sockfd, int port) {
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
        perror("bind");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    return 0;
}

int vladutz_listen(int sockfd) {
    if (listen(sockfd, VLADUTZ_BACKLOG) == -1) {
        perror("listen");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    return 0;
}

int vladutz_accept(int sockfd) {
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);
    int client_sockfd = accept(sockfd, (struct sockaddr *) &addr, &addr_len);
    if (client_sockfd == -1) {
        perror("accept");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    return client_sockfd;
}
