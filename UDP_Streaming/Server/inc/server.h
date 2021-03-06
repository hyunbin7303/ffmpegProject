

#ifndef _SERVER_H_
#define _SERVER_H_
#include "../../Common/inc/common.h"
#include "../../Common/inc/mySocket.h"


namespace UDP_Server
{
    class Server
    {
    public:
        Server() {std::cout <<"Server Constructor. " << std::endl;};
        Server(const std::string & addr, int port);
        ~Server(); // Destructor

        int LinuxUDPServerStart();
        int ServerStart(); // Currently developing this one.

        int packetReceive(char * info, size_t size);
        int timed_recv(char * msg, size_t, int maxWaitMS); // what is this?

        int getServerIp(char* ip);
        void generateResult(char * str);
        bool bindSocketForListening() const;
    private:
        mySocket *mySoc;

    };

    class UDP_runtimeError 
    {

    };


};



int FirstDataParse(char* DataInfoBuffer);
int isNumberCheck(char* str);
#endif
