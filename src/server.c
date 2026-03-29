#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>

int server(){
    int socket_d,new_client;

    if((socket_d = socket(AF_INET,SOCK_STREAM,0)) < 0){
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in sock_addr = {0};  // FIX

    sock_addr.sin_port = htons(9090);
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_addr.s_addr = INADDR_ANY;

    if(bind(socket_d,(struct sockaddr*)&sock_addr,sizeof(sock_addr)) == -1){
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if(listen(socket_d, 1) < 0){   // FIX
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while(1){
        if((new_client = accept(socket_d, NULL, NULL))<0){
            perror("accept");
            break;
        }
        
        while(1){    
            char recv_message[255] = {0};  // FIX

            int bytes = recv(new_client, recv_message, sizeof(recv_message)-1, 0); // FIX

            if(bytes <= 0){
                break;
            }

            recv_message[bytes] = '\0'; // FIX
            printf("Received from the client: %s\n", recv_message);
        }

        close(new_client); // FIX
    }

    close(socket_d);
    return 0;
}
