/*
 * @Author: liyunfei
 * @Date: 2021-08-24 09:37:54
 * @LastEditTime: 2021-08-24 17:28:41
 * @FilePath: /MyMiniHttpServer/include/HttpServer.h
 * @Description: 
 */
#if !defined(HTTPSERVER_H)
#define HTTPSERVER_H
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>
#include <strings.h>
#include <string.h>
#include <sys/stat.h>
#include <pthread.h>
#include <sys/wait.h>
#include <stdlib.h>

#include <string>
#include <thread>
#include <iostream>
#include <fstream>

using namespace std;



#endif // HTTPSERVER_H
