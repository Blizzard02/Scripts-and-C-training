/*Να γραφεί client-server εφαρμογή σε C στην οποία ο client θα
στέλνει μια αριθμητική παράσταση στον server, o server θα την
υπολογίζει και θα στέλνει το αποτέλεσμα στον client.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SIZE 1024

int main(int argc, char *argv[])
{
    int sock, i;
    int number1, number2, result;
    struct sockaddr_in addr; // Internet socket

    addr.sin_family = AF_INET; // Internet socket
    inet_aton(argv[1], &addr.sin_addr);
    addr.sin_port = htons(atoi(argv[2]));
    
    sock = socket(AF_INET, SOCK_STREAM, 0); // Stream socket
    connect(sock, (struct sockaddr *)&addr, sizeof(addr));

    printf("Enter the first number: ");
    scanf("%d", &number1);

    printf("Enter the second number: ");
    scanf("%d", &number2);

    send(sock, &number1, sizeof(int), 0);
    send(sock, &number2, sizeof(int), 0);
    //sendto(sock, msg, strlen(msg) + 1, 0, NULL, 0);

    recv(sock, &result, sizeof(int), 0);

    printf("The result of %d + %d is: %d\n", number1, number2, result);

    close(sock);

    return 0;
}
