#ifndef CLIENT_H
#define CLIENT_H

#include <WinSock2.h>
#include <ws2tcpip.h>
#include <Windows.h>
#include <sdkddkver.h>
#include <iostream>
#include <string>

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define SCK_VERSION2 0x0202
#pragma comment (lib, "ws2_32.lib")

using namespace std;


/**********
 * DEFINE
**********/
#define MAX_BUFFER_SIZE 200

#define IP_SERVER        "127.0.0.1"
#define PORT_SERVER      54000


/**********
 * API
**********/



class Client
{
private:
    string ipAddress;
    int port;
    SOCKET sock;
public:
    Client();

    /*
     * @brief main run
     */
    void run();

    bool initClient();


    /*
     * @brief create new socket listener
     * @return new socket
     */
    SOCKET createSocket();

    /*
     * @brief clean up wsa
     */
    void cleanUp();


    int sendMsg(string msg);

    int listenReponse(string& reponse);

    void closeSocket();


};

#endif // CLIENT_H
