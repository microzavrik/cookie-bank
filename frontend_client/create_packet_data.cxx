#include "create_packet_data.hxx"

#include "login_packet.hxx"
#include "undefined_packet.hxx"

namespace network
{
    namespace packets
    {

       network::packets::BasePacket CreatePacketData::CreatePacket(types::PacketType create_packet_type, const std::string& data_for_packet)
       {
            switch(create_packet_type)
            {
            case types::PacketType::Login:
                return packets::LoginPacket("123123");
                break;
            case types::PacketType::GetDataAccount:
                break;
            default:
                break;
            }

            return network::packets::UndefinedPacket();
       } 
    }
}