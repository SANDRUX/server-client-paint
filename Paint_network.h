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

//defined macro for localhost
#define ADDR "127.0.0.1"
//port number
#define PORT_NUM 50002 

namespace PNET
{

    struct address_structure
    {
        struct sockaddr_in addr; //socket addres structure
    };

    int sv_socket_create(struct address_structure *address); //socket creation for server

    int cl_socket_create(); //socket creation for client

    void send_request(int sfd, struct address_structure *address); //send request to server socket

    int handle_request(int sfd); //accept connection from client

    int send_packet(int sfd, int *buff, size_t size); //sebd data package 

    int recieve_packet(int sfd, int *buff, size_t size); //recieve data package

}

#endif