#include "create_packet_data.hxx"

namespace network
{
    namespace packets
    {
       template<typename T>
       T CreatePacketData::CreatePacket(types::PacketType create_packet_type, const std::string& data_for_packet)
       {
            switch(create_packet_type)
            {
            case types::PacketType::Login:
                break;
            case types::PacketType::GetDataAccount:
                break;
            default:
                break;
            }
       } 
    }
}