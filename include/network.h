#ifndef OS_2_PROJECT_NETWORK_H
#define OS_2_PROJECT_NETWORK_H

#include <netinet/in.h>


int vladutz_create_server_socket(int port);

int vladutz_accept_connection(int server_socket);

int vladutz_receive_data(int socket, char *buffer, int buffer_size);

int vladutz_send_data(int socket, const char *data, int data_length);

void vladutz_close_socket(int socket);

#endif //OS_2_PROJECT_NETWORK_H
