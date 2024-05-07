#include "user_info.hxx"

#include "system_utils.hxx"

namespace network
{
    void user_info::instance()
    {
        machine_id = system_utils::get_machine_id_linux();
    }
}