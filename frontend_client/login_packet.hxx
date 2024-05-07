#ifndef login_packet_hxx
#define login_packet_hxx

#include "base_packet.hxx"

namespace network
{
    namespace packets
    {
        struct LoginPacket : network::packets::BasePacket
        {
            std::string to_json() override;
        };
    }
}

#endif