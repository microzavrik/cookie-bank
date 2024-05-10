#include <iostream>
#include <thread>
#include <string>
#include <asio.hpp>
#include <nlohmann/json.hpp>

using namespace std;
using asio::ip::tcp;

class Client
{
public:
    Client(asio::io_context& io_context, const string& server_address, unsigned short server_port)
        : io_context_(io_context),
          socket_(io_context)
    {
        tcp::resolver resolver(io_context);
        tcp::resolver::results_type endpoints = resolver.resolve(server_address, to_string(server_port));
        asio::connect(socket_, endpoints);

        // Создаем JSON-строку с packet_type: "login"
        nlohmann::json loginPacket;
        loginPacket["packet_type"] = "login";
        string loginPacketStr = loginPacket.dump();

        // Отправляем JSON-строку серверу
        sendText(loginPacketStr);

        startListening();
    }

    void sendText(const string& text)
    {
        asio::write(socket_, asio::buffer(text + "\n"));
    }

private:
    void startListening()
    {
        socket_.async_read_some(asio::buffer(data_, max_length),
            [this](const asio::error_code& error, size_t bytes_transferred)
            {
                if (!error)
                {
                    // Process the received data
                    cout << "Received from server: " << string(data_, bytes_transferred) << endl;

                    // Continue listening for more data
                    startListening();
                }
            });
    }

    asio::io_context& io_context_;
    tcp::socket socket_;
    enum { max_length = 1024 };
    char data_[max_length];
};

int main()
{
    asio::io_context io_context;
    Client client(io_context, "127.0.0.1", 7777); // Connect to the server at 127.0.0.1:8080

    thread listener_thread([&io_context]() { io_context.run(); });

    string input;
    while (true)
    {
        getline(cin, input);
        if (input == "exit")
            break;
        client.sendText(input);
    }

    listener_thread.join();

    return 0;
}