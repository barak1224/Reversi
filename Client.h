#ifndef REVERSI_NETWORKCLIENT_H
#define REVERSI_NETWORKCLIENT_H

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <cstring>
#include <unistd.h>

#include "FileReader.h"
#include "ConsolePrinter.h"
#define MAX_MOVE 30
#define ERROR -1
#define DISCONNECT 0

class Client {
public:
    /**
     * Destructor
     */
    ~Client();

    /**
     * Constructor
     */
    Client(Printer *printer);

    /**
     * The method connecting the client to the server
     */
    void connectToServer();

    /**
    * The method send the player chose to the other player
    */
    bool send(string message);

    /**
     * The method receive the other player move
     * @return the coordinate received by stream
     */
    string receive();

private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
    Printer *printer;
};


#endif //REVERSI_NETWORKCLIENT_H