#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

//#define SIZE 1024

int main(int argc, char *argv [])
{
    int psock, sock;
    int number1, number2, result;
    struct sockaddr_in addr; // Internet socket

    addr.sin_family = AF_INET; // Internet socket
    addr.sin_addr.s_addr = htonl(INADDR_ANY); // All interfaces
    addr.sin_port = htons(atoi(argv[1]));
    
    psock = socket(AF_INET, SOCK_STREAM, 0); // Stream socket
    bind(psock, (struct sockaddr *)&addr, sizeof(addr));
    listen(psock, 1);

    while(1) 
    {
        printf("\nwaiting for new connection (port : %s) ...\n", argv[1]);

        sock = accept(psock, NULL, NULL);

        printf("connection established...\n");

        recv(sock, &number1, sizeof(int), 0);
        recv(sock, &number2, sizeof(int), 0);

        result = number1 + number2;
        send(sock, &result, sizeof(int), 0);

        close(sock);
        printf("\nconnection closed...\n");
    }

    close(psock);
    unlink(argv[1]);

    return 0;
}