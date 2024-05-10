#ifndef USER_SESSION_HH
#define USER_SESSION_HH

#include <asio.hpp>
#include <iostream>
#include <memory>

using asio::ip::tcp;

namespace net
{
    struct user_session : public std::enable_shared_from_this<net::user_session>
    {
        user_session(tcp::socket socket);
        void start();
    private:
        void read_data();
    private:
        tcp::socket socket_;
        enum { max_length = 1024 };
        char data_[max_length];
    };

}
#endif