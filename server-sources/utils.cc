#include "utils.hh"

#include <ctime>
#include <iomanip>
#include <sstream>
#include <iostream>

#include <nlohmann/json.hpp>

namespace utils
{
    [[nodiscard]] std::string current_time()
    {
        std::time_t now = std::time(nullptr);
        std::tm *currentTime = std::localtime(&now);

        std::ostringstream oss;
        oss << std::put_time(currentTime, "%Y-%m-%d %H:%M:%S");

        return oss.str();
    }

    namespace log
    {
        void show_message(const std::string& msg)
        {
            std::cout << "[" << current_time() << "]: " << msg << std::endl;
        }
    }

    namespace packet
    {
        [[nodiscard]] packets::packet_request_t packet_type_identifier(const std::string& content)
        {
            nlohmann::json json_packet = nlohmann::json::parse(content);
            std::string packet_type = json_packet["packet_type"];
            std::cout << "Packet type: " << packet_type << std::endl;
            str_to_packet_request_t(packet_type);
        }

        [[nodiscard]] packets::packet_request_t str_to_packet_request_t(const std::string& content)
        {
            if(content == "login") {
                return packets::packet_request_t::login;
            }
            else {
                return packets::packet_request_t::undefined;
            }
        }
    }
}