#include "create_packet_data.hxx"

#include "login_packet.hxx"
#include "undefined_packet.hxx"

#include "check_json_format_valid.hxx"

namespace network
{
    namespace packets
    {

       network::packets::BasePacket CreatePacket(types::PacketType create_packet_type, const std::string& data_for_packet)
       {
            switch(create_packet_type)
            {
                case types::PacketType::Login:
                    if(!utils::check_json_format_valid(data_for_packet, create_packet_type)) {
                        return network::packets::UndefinedPacket();
                    }
                    
                    return packets::LoginPacket("123123");
            case types::PacketType::GetDataAccount:
                break;
            default:
                break;
            }

            return network::packets::UndefinedPacket();
       } 
    }
}