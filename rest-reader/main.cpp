#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <boost/asio.hpp>

int main(int argc, char *argv[])
{
    try {
        using boost::asio::ip::tcp;

        boost::asio::io_service io_service;
        tcp::iostream socketstream(tcp::resolver::query{"localhost", "9000"});
        std::string respStr;

        auto execCmd = [&socketstream, &respStr](std::string cmd) -> void
        {
            socketstream << cmd;
            while(std::getline(socketstream, respStr) && respStr != "\r") {
                std::cout << respStr << std::endl;
            }
            socketstream.flush();
        };

        execCmd("/get");
        execCmd("/delete/ZZ");
        execCmd("/get");
        execCmd("/commit");

        /*
        socketstream << "/get";
        while(std::getline(socketstream, respStr) && respStr != "\r") {
            std::cout << respStr << std::endl;
        }
        socketstream.flush();

        socketstream << "/delete/ZZ";
        while(std::getline(socketstream, respStr) && respStr != "\r") {
            std::cout << respStr << std::endl;
        }
        socketstream.flush();

        */
        socketstream.close();
    }
    catch(std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "Done ..." << std::endl;
    return 0;
}
