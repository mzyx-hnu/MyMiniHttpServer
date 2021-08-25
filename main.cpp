#define _GLIBCXX_USE_CXX11_ABI 0

//#include "HttpServer.h"
#include "HttpRequest.h"
#include "Config.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct http_request
{
    string method;
    string url;
    string version;
    map<string,string> header;
    vector<string> body;
};


int main(int, char**) {
    int server_sockfd, client_sockfd;
    int server_len, client_len;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(10000);
    server_len = sizeof(server_address);
    bind(server_sockfd, (sockaddr*)&server_address, server_len);

    listen(server_sockfd, 5);
    while (1)
    {
        char ch[5000];
        char send_str[] = "hello world!\n";
        client_len = sizeof(client_address);
        client_sockfd = accept(server_sockfd, (sockaddr*)&client_address, (socklen_t*)&client_len);
        read(client_sockfd, &ch, 5000);
        //printf("%s", ch);
        string req(ch);
        HttpRequest request(req);

        cout << "method:" << request.GetMethod() << endl;
        cout << "url:" << request.GetUrl() << endl;
        cout << "version:" << request.GetVersion() << endl;
        cout << "headers:" << endl;
        auto header = request.GetHeader();
        for(map<string,string>::iterator iter = header.begin(); iter != header.end(); iter++)
        {
            cout<<"\"";
            cout<<iter->first<<"\",\""<<iter->second;
            cout<<"\""<<endl;
        }
        cout << "body:" << endl;
        auto body = request.GetBody();
        int len = body.size();
        for (int i = 0; i < len; i++)
        {
            cout<<body[i]<<endl;
        }
        
        write(client_sockfd, &send_str, sizeof(send_str)/sizeof(send_str[0]));
        close(client_sockfd);
    }
    
}