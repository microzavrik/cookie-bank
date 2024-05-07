#ifndef packet_types_hxx
#define packet_types_hxx

#include <string>

namespace types
{
    enum class PacketType
    {
        Login,
        GetDataAccount,
        Undefined
    };

    PacketType str_to_packet_type(const std::string& str_type);
}

#endif