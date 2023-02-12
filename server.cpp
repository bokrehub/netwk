//server code =====>
#include <iostream>
#include <fstream>
#include <boost/asio.hpp>
#include <boost/array.hpp>

using namespace boost::asio;
using namespace boost::asio::ip;

int main(){

    io_service io_service; // create io_service object

tcp::endpoint endpoint(address::from_string("192.168.1.500"), 12345);

    tcp::acceptor acceptor(io_service, endpoint);  // create acceptor object and bind it to endpoint

    while (true)
    {
        tcp::socket socket (io_service); // create socket object
        acceptor.accept(socket); // accept connection 

        //open the text file
        std::ifstream file("text.txt");
        std::string content ((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));

        //send the file content
        write(socket, buffer(content));

        //close the socket
        socket.close();
 
    }


    return 0;
}

