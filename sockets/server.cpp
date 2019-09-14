
// Server side C/C++ program to demonstrate Socket programming 
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h>
#include <vector>
#include <string>
#include <iostream>

#define PORT 8080

using namespace std;

class SocketServer{
private:
    int server_fd;
    int new_socket;
    int valread;
    struct sockaddr_in address;
    int addrlen;
    int opt = 1;
    int socket_set;
    int bind_valid;
    int listen_valid;
    vector<int> accepted_sockets;
public:
    SocketServer(){
        addrlen = sizeof(address);
        address.sin_family = AF_INET; 
        address.sin_addr.s_addr = INADDR_ANY; 
        address.sin_port = htons( PORT );
    }
    ~SocketServer(){}
    //create socket
    int initSocket(){
        server_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_fd == -1){ 
            perror("socket failed"); 
            exit(EXIT_FAILURE); 
        }
        return server_fd;
    }
    // attach socket to a PORT
    int setSocket(){
        socket_set = setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
        if (socket_set){
            perror("setsockopt"); 
            exit(EXIT_FAILURE); 
        }
    }
    //bind and listen
    int bindAndListen(){
        if (bind(server_fd, (struct sockaddr *)&address,sizeof(address))<0) { 
            perror("bind failed"); 
            exit(EXIT_FAILURE); 
        } 
        if (listen(server_fd, 3) < 0){ 
            perror("listen"); 
            exit(EXIT_FAILURE); 
        }
    }
    int acceptClients(){
        if ( (new_socket = accept(server_fd, (struct sockaddr *)&address,  
                       (socklen_t*)&addrlen)) <0 ){ 
            perror("accept"); 
            exit(EXIT_FAILURE); 
        }
        else{
            accepted_sockets.push_back(new_socket);
        }
    }
    int readAndSend(char *rcvMsg, char* sendMsg){
        for (int i=0; i < accepted_sockets.size(); i++) {
            read( accepted_sockets[i] , rcvMsg, 1024);
            printf("received : %s\n",rcvMsg );
            send(new_socket , sendMsg , strlen(sendMsg) , 0 );
        }
    }
};

int main(int argc, char const *argv[]) 
{ 
    char buffer[1024] = {0}; 
    char *sendMsg;

    SocketServer myserver;
    myserver.initSocket();
    myserver.setSocket();
    myserver.bindAndListen();
    myserver.acceptClients();
    string sendString;
    string doString;
    do{        
        cout << "Send: " <<endl;
        cin >> sendString;
        sendMsg = (char*)sendString.c_str();
        myserver.readAndSend(buffer, sendMsg);
        cout << "Send another message (y/n): ";
        cin >> doString;
    }while(doString == "Y" || doString == "y");
    

    return 0; 
} 
