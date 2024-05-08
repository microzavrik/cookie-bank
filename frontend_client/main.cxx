#include "network_client.hxx"

int main(int argc, char* argv[])
{
    try
    {
        asio::io_context ios;
        network::TCPClient client(ios, "127.0.0.1", 3333);
        client.send_messages("", types::PacketType::Login);

        ios.run();
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        return -1;
    }
    return 0;
}