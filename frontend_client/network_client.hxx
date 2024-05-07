#include <iostream>
#include <asio.hpp>
#include <thread>

#include "user_info.hxx"

using namespace asio;
using namespace asio::ip;

namespace network
{
    class TCPClient
    {
    public:
        TCPClient(io_context &ios, const std::string &host, short port);

    private:
        void send_messages(const std::string& send_data);
        void received_messages();

        tcp::socket socket_;
        network::user_info usr_info;
    };

}