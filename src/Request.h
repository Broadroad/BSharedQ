#pragma once

using namespace std;
class Request
{
private:
    string requestid_;
    string data_;
public:
    Request(){};
    Request(string id, string data);
    ~Request();

    string RequestId() {return requestid_;}
    string Data() {return data_;}
};

Request::Request(string id, string data) : requestid_(id), data_(data) {}

Request::~Request() {}
