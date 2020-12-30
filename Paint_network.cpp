#include "Paint_network.h"

    //using namespace PNET;

    int PNET::sv_socket_create(struct PNET::address_structure * address)
    {
        if (address == NULL)
        {
            memset(address, 0, sizeof(struct PNET::address_structure));

            address->addr.sin_family = AF_INET;
            address->addr.sin_port = htons(PORT_NUM);

            inet_aton(ADDR, &address->addr.sin_addr);
        }
        int sfd = socket(AF_INET, SOCK_STREAM, 0);

        if (sfd == -1)
        {
            printf("Error occured when creating server socket!");
            exit(EXIT_FAILURE);
        }

        if (bind(sfd, (struct sockaddr *)&address->addr, sizeof(struct sockaddr)) == -1)
        {
            printf("Error occured when binding socket!");
            exit(EXIT_FAILURE);
        }

        if (listen(sfd, 1) == -1)
        {
            printf("Errorc occured when setting sockets behaviour as listener!");
            exit(EXIT_FAILURE);
        }

        return sfd;
    }

    int PNET::cl_socket_create()
    {
        int sfd = socket(AF_INET, SOCK_STREAM, 0);

        if (sfd == -1)
        {
            printf("Error occured when creating socket for client!");
            exit(EXIT_FAILURE);
        }

        return sfd;
    }

    void PNET::send_request(int sfd, struct PNET::address_structure *address)
    {
        int status = connect(sfd, (struct sockaddr *)address, sizeof(struct PNET::address_structure));

        if (status == -1)
        {
            printf("Error occureed when connecting to socket!");
            exit(EXIT_FAILURE);
        }
    }

    int PNET::handle_request(int sfd)
    {
            int cfd = accept(sfd, NULL, NULL);

            if (cfd == -1)
            {
                printf("Error occurred when accepting request!");
                exit(EXIT_FAILURE);
            }
 
        return cfd;        
    }

    int PNET::recieve_packet(int sfd, int *buff, size_t size)
    {
        int numRead;

        numRead = read(sfd, buff, size);

        if (numRead == -1)
        {
            printf("Error occured when recieving packet from socket!");
            exit(EXIT_FAILURE);
        }
        
        return numRead;    
    }

    int PNET::send_packet(int sfd, int *buff, size_t size)
    {
        int numWrite;

       numWrite = write(sfd, buff, size);

        if (numWrite == -1)
        {
            printf("Error occured when sending packet to socket!");
            exit(EXIT_FAILURE);
        }
       
       return numWrite;
    }

    void PNET::close_socket(int sfd)
    {
        if (close(sfd) == -1)
        {
            printf("Error occured when closing socket!");
            exit(EXIT_FAILURE);
        }
    }
