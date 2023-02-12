//client code =====>
#include <iostream>
#include <fstream>
#include <boost/asio.hpp>
#include <boost/array.hpp>

using namespace boost::asio;
using namespace boost::asio::ip;

int main(){

    io_service io_service; // create io_service object

    //connect to server
    tcp::socket socket (io_service);
    socket.connect(tcp::endpoint(address::from_string("127.0.0.1"), 12345));

    //receive the contents of file;
    boost::array <char, 1024> buf;
    size_t len = socket.read_some(buffer(buf));
    
    //writ the content in the local file:)
    std::ofstream file("received_text.txt");
    file.write(buf.data(), len);
    file.close();

    //close the socket
    socket.close(); 

    return 0;
}

