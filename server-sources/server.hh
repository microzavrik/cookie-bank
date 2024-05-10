#ifndef SERVER_HH
#define SERVER_HH

#include "user_session.hh"
#include "cookie_users_db.hh"

#include <vector>
#include <thread>

namespace net
{
    struct server
    {
        server(asio::io_context& ios, unsigned short port);
    private:
        void start_accept();
    private:
        asio::io_context& ios_;
        tcp::acceptor acceptor_;
        std::vector<std::thread> threads_;
        net::db::cookie_users_db db_;
    };
}

#endif