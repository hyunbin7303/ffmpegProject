/*
	=============================================================
	File:	Common.h
	Date:	Jan. 21 2018
	Description: This file will contain all the common includes,
	constants, struct and function prototypes for the
	completion of this program.
	=============================================================
*/

#ifndef _COMMON_H_
#define _COMMON_H_
#pragma warning (disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#ifdef _WIN32

#include <winsock2.h>
#include <windows.h>
#else
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <ctype.h>
#define SOCKET_ERROR -1
#define INVALID_SOCKET -1

#define ERROR 0
#endif // _WIN32

#define FIRST_CONNECTION_FAIL -10
#define SIZEBUF 22000

#define WINDOW_SERVER 1
#define WINDOW_CLIENT 2
#define LINUX_SERVER 3
#define LINUX_CLIENT 4

#define FAIL_WINDOW -1
#define FAIL_LINUX -2

#define SERVER_ARG 3
#define CLIENT_ARG 10
#define INVALID_CMD_ARG -1

#define TCP 10
#define UDP 20

#define TIMEOUT_MS 
#define SERVICE_DONE 100
#define SERVICE_RESTART 200
#define SERVICE_ERROR -100

typedef struct
{
	int Protocol;
	char* IpAddr;
	int portNum;
	int numBlock;
	int BlockSize;
}CommandLineValues;

CommandLineValues EachValue;
char* ipAdd;
int commandLineParser(int argc, char** argv);
int isNumberCheck(char* str);


#endif
