/*
 * @Author: liyunfei
 * @Date: 2021-08-24 22:02:27
 * @LastEditTime: 2021-08-25 16:37:16
 * @FilePath: /MyMiniHttpServer/include/HttpRequest.h
 * @Description: 
 */
#if !defined(HTTPREQUEST_H)
#define HTTPREQUEST_H
#define _GLIBCXX_USE_CXX11_ABI 0
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class HttpRequest
{
private:
    string method;
    string url;
    string version;
    map<string,string> header;
    vector<string> body;
public:
    HttpRequest(string http_data);
    inline const string& GetMethod(){return method;}
    inline const string& GetUrl(){return url;}
    inline const string GetVersion(){return version;}
    inline const map<string, string>& GetHeader(){return header;}
    inline const vector<string>& GetBody(){return body;}
    ~HttpRequest(){}
    //void parse_request(string http_data);
};



#endif // HTTPREQUEST_H
