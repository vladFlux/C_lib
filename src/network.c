#include "network.h"
#include "network_utils.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>


int vladutz_create_server_socket(int port) {
    int server_socket;
    struct sockaddr_in server_address;

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        return -1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("bind");
        close(server_socket);
        return -1;
    }

    if (listen(server_socket, 3) == -1) {
        perror("listen");
        close(server_socket);
        return -1;
    }

    return server_socket;
}

int vladutz_accept_connection(int server_socket) {
    int client_socket;
    struct sockaddr_in client_address;
    int addrlen = sizeof(client_address);

    if ((client_socket = accept(server_socket, (struct sockaddr *) &client_address, (socklen_t * ) & addrlen)) == -1) {
        perror("accept");
        return -1;
    }

    return client_socket;
}

int vladutz_receive_data(int socket, char *buffer, int buffer_size) {
    int bytes_received;

    if ((bytes_received = recv(socket, buffer, buffer_size, 0)) == -1) {
        perror("recv");
        return -1;
    }

    return bytes_received;
}

int vladutz_send_data(int socket, const char *data, int data_length) {
    int bytes_sent;

    if ((bytes_sent = send(socket, data, data_length, 0)) == -1) {
        perror("send");
        return -1;
    }

    return bytes_sent;
}

void vladutz_close_socket(int socket) {
    close(socket);
}
