/*
 * @Author: liyunfei
 * @Date: 2021-08-24 22:02:05
 * @LastEditTime: 2021-08-25 15:43:32
 * @FilePath: /MyMiniHttpServer/include/HttpRequest.cpp
 * @Description: 
 */
#include "HttpRequest.h"

std::vector<std::string> splitString(std::string srcStr, std::string delimStr,bool repeatedCharIgnored)
{
    std::vector<std::string> resultStringVector;
    std::replace_if(srcStr.begin(), srcStr.end(), [&](const char& c){if(delimStr.find(c)!=std::string::npos){return true;}else{return false;}}/*pred*/, delimStr.at(0));//将出现的所有分隔符都替换成为一个相同的字符（分隔符字符串的第一个）
    size_t pos=srcStr.find(delimStr.at(0));
    std::string addedString="";
    while (pos!=std::string::npos) {
        addedString=srcStr.substr(0,pos);
        if (!addedString.empty()||!repeatedCharIgnored) {
            resultStringVector.push_back(addedString);
        }
        srcStr.erase(srcStr.begin(), srcStr.begin()+pos+1);
        pos=srcStr.find(delimStr.at(0));
    }
    addedString=srcStr;
    if (!addedString.empty()||!repeatedCharIgnored) {
        resultStringVector.push_back(addedString);
    }
    return resultStringVector;
}

HttpRequest::HttpRequest(string http_data)
{
    vector<string> lines = splitString(http_data,"\n",false);

    vector<string> first_line = splitString(lines[0]," ",false);

    if(first_line.size()==3){
        method = first_line[0];
        url = first_line[1];
        version = first_line[2];
    }
    size_t i;
    for(i = 1;i<lines.size();i++){
        if(lines[i]==""||lines[i]=="\r"){
            break;
        }
        size_t pos = lines[i].find_first_of(':');
        if(pos==string::npos){
            // cerr<<"bad request"<<endl;
            // cout<<"this lines ascii is"<<endl;
            // for(auto j:lines[i]){
            //     cout<<(int)(j)<<" ";
            // }
            // cout<<endl;
            break;
        }
        string key = lines[i].substr(0,pos);
        string val;
        int len = lines[i].length();
        //去除val前可能存在的空格
        if(lines[i][pos+1]==' '){
            val = lines[i].substr(pos+2, len-pos-3);
        }
        else{
            val = lines[i].substr(pos+1, len-pos-2);
        };
        header.insert(pair<string,string>(key,val));
    }
    for(; i < lines.size(); i++)
    {
        if(lines[i] == "\r"||lines[i] == "")continue;
        int len = lines[i].length();
        body.push_back(lines[i].substr(0,len));
    }
}
