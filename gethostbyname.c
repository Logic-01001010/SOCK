#include<stdio.h>
#include<netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char* argv[])
{
    struct hostent *host;

    if(argc != 2)
    {
        printf("Usage : %s <Domain>\n", argv[0]);
        return -1;
    }

    if((host = gethostbyname( argv[1] )) == NULL)
    {
        fprintf(stderr, "%s는 등록되지 않은 서버명입니다.\n", argv[1]);
        return -1;
    }


    char *address = inet_ntoa(*(struct in_addr *)host->h_addr);
    fprintf(stdout, "%s\n", address);


    return 0;
}
