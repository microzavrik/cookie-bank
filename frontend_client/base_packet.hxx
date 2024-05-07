#ifndef base_packet
#define base_packet

#include "packet_types.hxx"

namespace network
{
    namespace packets
    {
        struct BasePacket
        {
            BasePacket(const std::string& type_str, types::PacketType pack_type) : pack_type_str(type_str), pack_type_(pack_type) { }
            virtual std::string to_json();
            ~BasePacket() { }
            types::PacketType pack_type_;
            std::string pack_type_str;
        };
    }
}

#endif