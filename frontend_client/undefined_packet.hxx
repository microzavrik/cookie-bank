#ifndef undefined_packet_hxx
#define undefined_packet_hxx

#include "base_packet.hxx"

namespace network
{
    namespace packets
    {
        struct UndefinedPacket : network::packets::BasePacket
        {
            UndefinedPacket() : BasePacket("undefined", types::PacketType::Undefined) { }
        };
    }
}

#endif