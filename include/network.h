#ifndef OS_2_PROJECT_NETWORK_H
#define OS_2_PROJECT_NETWORK_H

#include <stddef.h>


#define VLADUTZ_PORT 8080
#define VLADUTZ_BACKLOG 10

int vladutz_socket();

int vladutz_bind(int sockfd, int port);

int vladutz_listen(int sockfd);

int vladutz_accept(int sockfd);

#endif //OS_2_PROJECT_NETWORK_H
