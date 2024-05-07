#ifndef create_packet_data_hxx
#define create_packet_data_hxx

#include <string>

#include "packet_types.hxx"
#include "base_packet.hxx"


namespace network
{
    namespace packets
    {
        network::packets::BasePacket CreatePacket(types::PacketType create_packet_type, const std::string& data_for_packet);
    }
}

#endif