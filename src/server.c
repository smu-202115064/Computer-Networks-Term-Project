/**
 * @file server.c
 * @author hepheir (202115064@sangmyung.kr)
 * @brief Computer Networks (HAEA0004-1) Term Project Server
 * @version 0.1
 * @date 2024-05-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <arpa/inet.h>

#define HOST "127.0.0.1"
#define PORT 9000


int main(void)
{
    char rbuf[256];
    char wbuf[256];
    int msg_cnt = 0;

    struct sockaddr_in sin, cli;
    int sd, ns, clientlen = sizeof(cli);

    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket");
        exit(1);
    }

    memset((char *)&sin, '\0', sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORT);
    sin.sin_addr.s_addr = inet_addr(HOST);

    if (bind(sd, (struct sockaddr *)&sin, sizeof(sin)))
    {
        perror("bind");
        exit(1);
    }
    if (listen(sd, 5))
    {
        perror("listen");
        exit(1);
    }

    printf("Waiting...\n");

    if ((ns = accept(sd, (struct sockaddr *)&cli, &clientlen)) == -1)
    {
        perror("accept");
        exit(1);
    }

    printf("[Client Connected]\n");

    while (true)
    {
        if (read(ns, rbuf, sizeof(rbuf)) == -1)
        {
            perror("recv");
            exit(1);
        }

        if (strcmp(rbuf, "c") == 0 || strcmp(rbuf, "C") == 0)
        {
            printf("[Message Cnt Response (cnt: %d) ]\n", msg_cnt);
            sprintf(wbuf, "%d", msg_cnt);
        }
        else if (strcmp(rbuf, "q") == 0 || strcmp(rbuf, "Q") == 0)
        {
            printf("[Client Disconnected]\n");
            break;
        }
        else {
            printf("Received Message: %s\n", rbuf);
            strcpy(wbuf, rbuf);
            msg_cnt++;
        }

        if (write(ns, wbuf, strlen(wbuf) + 1) == -1)
        {
            perror("send");
            exit(1);
        }
    }
    close(ns);
    close(sd);

    return 0;
}