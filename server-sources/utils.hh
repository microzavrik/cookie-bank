#ifndef UTILS_HH
#define UTILS_HH

#include "packet_request_t.hh"

#include <string>

namespace utils
{
    [[nodiscard]] std::string current_time();

    namespace log
    {
        void show_message(const std::string& msg);
    }

    namespace packet
    {
        [[nodiscard]] packets::packet_request_t packet_type_identifier(const std::string& content);
        [[nodiscard]] packets::packet_request_t str_to_packet_request_t(const std::string& content);
    }
}

#endif