#ifndef base_packet
#define base_packet

#include "packet_types.hxx"

namespace network
{
    namespace packets
    {
        struct BasePacket
        {
            virtual std::string to_json();
            ~BasePacket() { }
            types::PacketType pack_type_;
            std::string pack_type_str;
        };
    }
}

#endif