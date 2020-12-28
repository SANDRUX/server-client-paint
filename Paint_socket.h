#ifndef PAINT_SOCKET_H
#define PAINT_SOCKET_H

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>

#define ADDR "127.0.0.1"
#define PORT_NUM 50002

namespace PNET
{

    struct address_structure
    {
        struct sockaddr_in addr; //socket addres structure
    };

    int sv_socket_create(struct address_structure *address);

    int cl_socket_create();

    void send_request(int sfd, struct address_structure *address);

    void handle_request(int sfd);

    int send_packet(int sfd, int *buff, size_t size);

    int recieve_packet(int sfd, int *buff, size_t size);

}

#endif