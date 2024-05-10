#include "server.hh"
#include "utils.hh"

namespace net
{
    server::server(asio::io_context& ios, unsigned short port)
        : ios_(ios), acceptor_(ios, tcp::endpoint(tcp::v4(), port)) 
        { 
            db_.init_connect();
            utils::log::show_message("Start server"); 
            start_accept();
        }
    
    void server::start_accept()
    {
        std::shared_ptr<tcp::socket> socket(new tcp::socket(ios_));
        acceptor_.async_accept(*socket, [this, socket](const asio::error_code& error)
        {
            if(!error)
            {
                std::shared_ptr<net::user_session> new_session = std::make_shared<user_session>(std::move(*socket));
                threads_.emplace_back([new_session]() { new_session->start(); });
            }
            start_accept();
        });
    }
}