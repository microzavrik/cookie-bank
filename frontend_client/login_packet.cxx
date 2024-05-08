#include "login_packet.hxx"

#include <nlohmann/json.hpp>

namespace network
{
    namespace packets
    {
        std::string LoginPacket::to_json()
        {
            nlohmann::json json;
            json["packet_type"] = pack_type_str;
            json["machine_id"] = machine_id_;

            return json.dump();
        }

        void LoginPacket::convert_to_object(const std::string &source) { return; }
    }
}