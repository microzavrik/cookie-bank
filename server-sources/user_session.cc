#include "user_session.hh"
#include "utils.hh"

namespace net
{
    user_session::user_session(tcp::socket socket) : socket_(std::move(socket)) { }
    
    void user_session::start() { read_data(); }
    
    void user_session::read_data()
    {
        auto self(shared_from_this());
        
        socket_.async_read_some(asio::buffer(data_, max_length),
            [this, self](const asio::error_code& error, size_t bytes_transferred)
            {
                if(!error)
                {
                    utils::log::show_message(std::string(data_, bytes_transferred));
                    utils::packet::packet_type_identifier(std::string(data_, bytes_transferred));
                    read_data();
                }
            });
    }
}