#ifndef RDPCLIENT_H
#define RDPCLIENT_H
#include <string>
#include <vector>
#include <boost/asio.hpp>

class RDPClient
{
public:
    RDPClient();

    std::string fileds();
    std::string get(std::string name);
    std::vector<std::string> get();
    bool set(std::string newEntry);
    bool set (std::string name, std::string field, std::string newValue);
    bool erase(std::string name);
    bool commit();
};

#endif // RDPCLIENT_H
