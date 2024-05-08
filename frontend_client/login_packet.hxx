#ifndef login_packet
#define login_packet

#include "base_packet.hxx"

#include "system_utils.hxx"

namespace network
{
    namespace packets
    {
        struct LoginPacket : public BasePacket
        {
            std::string machine_id_;

            LoginPacket()
                : BasePacket("login", types::PacketType::Login), machine_id_(system_utils::get_machine_id_linux()) { }

            std::string to_json() override;
            void convert_to_object(const std::string& source) override;
        };
    }
}

#endif
