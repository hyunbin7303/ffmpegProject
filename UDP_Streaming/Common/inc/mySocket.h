#ifndef _mySocket
#define _mySocket

#include "./myHostInfo.h"
#include "mySocketException.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>
#include <string>


class mySocket
{
public:
    mySocket(){}
    mySocket(int); 
    mySocket(const std::string & address, int port);
    virtual ~mySocket()
    {
        close(socketId);
    }
    int getSocketId() const { return socketId; }
	int getPortNumber() const { return portNumber; }
    std::string getAddr() const {return address; }
    void setSendBufSize(int);
    void setReceiveBufSize(int);
    int bindSocket() const;

    void setReadBufSize(unsigned int size) throw(MySocketException);

    
    mySocket& operator <<(const string & s);// writing string to socket
    mySocket& operator >>(const string & s);// Read data to string from socke.t

    mySocket(const &mySocket); // Need investigation
    // Prevent the user from trying to use exact copy of this obj.
    int socketId;

protected:
    int portNumber;
    std::string  address;
    struct addrinfo * _addrinfo;

public:
    enum TypeSocket
    {
        TCP_Socket = SOCK_STREAM,
        UDP_Socket = SOCK_DGRAM,
        Unknown = -1
    };
    enum LayerProtocol
    {
        IPv4Protocol = AF_INET,
        IPv6Protocol = AF_INET6,
        Unknwon = -1
    };
    enum ReadResult
    {
        ARRIVED = 0,
        TIMEOUT= ETIMEDOUT,
        EXCEPTION = 255
    };


};

// TODO : requires to delete or move to other directory.
class myTcpSocket : public mySocket
{
public:
	myTcpSocket() {};
	~myTcpSocket() {};
	myTcpSocket(int portId) : mySocket(portId) { };
	int sendMessage(string&);
	int recieveMessage(string&);
	void bindSocket();
	myTcpSocket* acceptClient(string&);
	void listenToClient(int numPorts = 5);
	virtual void connectToServer(string&,hostType);

};
#endif