#ifndef login_packet
#define login_packet

#include "base_packet.hxx"

namespace network
{
    namespace packets
    {
        struct LoginPacket : public BasePacket
        {
            std::string machine_id_;

            LoginPacket(const std::string& machineid)
                : BasePacket("login", types::PacketType::Login), machine_id_(machineid) { }

            std::string to_json() override;
        };
    }
}

#endif
