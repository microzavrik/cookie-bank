#include "network_client.hxx"

#include "create_packet_data.hxx"
#include "packet_types.hxx"

namespace network
{
    TCPClient::TCPClient(io_context &ios, const std::string &host, short port) : socket_(ios)
    {
        usr_info.instance();

        tcp::resolver resolver(ios);
        tcp::resolver::results_type endpoints = resolver.resolve(host, std::to_string(port));
        asio::connect(socket_, endpoints);
        std::thread(&network::TCPClient::received_messages, this).detach();
    }

    void TCPClient::send_messages(const std::string& send_data)
    {
        asio::write(socket_, asio::buffer(send_data + "\n"));
    }

    void TCPClient::received_messages()
    {
        try
        {
            while(true)
            {
                asio::streambuf buf;
                asio::read_until(socket_, buf, '\n');
                std::istream input_stream(&buf);
                std::string data;
                std::getline(input_stream, data);
                std::cout << "Received: " << data << std::endl;
            }
        }
        catch(const std::exception& ex)
        {
            std::cerr << ex.what() << std::endl;
        }
    }
}