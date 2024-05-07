#ifndef check_json_format_valid_hxx
#define check_json_format_valid_hxx

#include "packet_types.hxx"
#include <string>

namespace utils
{
    bool check_json_format_valid(const std::string& data, types::PacketType check_type);
}

#endif