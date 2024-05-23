/**
 * @file client.c
 * @author hepheir (202115064@sangmyung.kr)
 * @brief Computer Networks (HAEA0004-1) Term Project Client
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
    int sd;
    char buf[256];
    struct sockaddr_in sin;

    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket");
        exit(1);
    }

    memset((char *)&sin, '\0', sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORT);
    sin.sin_addr.s_addr = inet_addr(HOST);

    if (connect(sd, (struct sockaddr *)&sin, sizeof(sin)))
    {
        perror("connect");
        exit(1);
    }

    while (true) {
        printf("Input message: ");
        scanf("%s", buf);

        if (write(sd, buf, sizeof(buf)) == -1)
        {
            perror("send");
            exit(1);
        }

        if (strcmp(buf, "c") == 0 || strcmp(buf, "C") == 0) {
            printf("[Message Cnt Request]\n");
        }
        else if (strcmp(buf, "q") == 0 || strcmp(buf, "Q") == 0) {
            printf("[Disconnection Request]\n");
            break;
        }

        if (read(sd, buf, sizeof(buf)) == -1)
        {
            perror("recv");
            exit(1);
        }

        printf("[Text From Server : %s ]\n", buf);
    }

    close(sd);
    return 0;
}