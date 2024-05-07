#include "packet_types.hxx"

namespace types
{
    PacketType str_to_packet_type(const std::string& str_type)
    {
        if(str_type == "login") {
            return types::PacketType::Login;
        }
        else if(str_type == "get_data_account") {
            return types::PacketType::GetDataAccount;
        }
        else {
            return types::PacketType::Undefined;
        }
    }
}