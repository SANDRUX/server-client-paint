#include "Paint_socket.h"

    using namespace PNET;

    void sv_socket_create(struct address_structure *address)
    {
        memset(address, 0, sizeof(struct address_structure));

        address->addr.sin_family = AF_INET;
        address->addr.sin_port = htons(PORT_NUM);
        inet_aton(ADDR, &address->addr.sin_addr);

        int sfd = socket(AF_INET, SOCK_STREAM, 0);

        if (sfd == -1)
        {
            printf("Error occured when creating socket!");
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
    }

    void send_request(int sfd, struct address_structure *address)
    {
        int status = connect(sfd, (struct sockaddr *)address, sizeof(struct address_structure));

        if (status == -1)
        {
            printf("Error occureed when connecting to socket!");
            exit(EXIT_FAILURE);
        }
    }

    void handle_request(int sfd, char *buff, size_t size)
    {
        for (;;)
        {
            int cfd = accept(sfd, NULL, NULL);

            if (cfd == -1)
            {
                printf("Error occurred when accepting request!");
                exit(EXIT_FAILURE);
            }

            int numRead;


            while ((numRead = read(cfd, buff, size)) > 0)
            {
                if (write(cfd, buff, size) != numRead)
                {
                    printf("Error ocurred when writing to socket!");
                    exit(EXIT_FAILURE);
                }
            } 
        }

        
    }

    void send_packet(int sfd, char *buff, size_t size)
    {
        send(sfd, buff, size, (int)NULL);
    }
