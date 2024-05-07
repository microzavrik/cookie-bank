#include "system_utils.hxx"

namespace system_utils
{
    std::string get_machine_id_linux()
    {
        std::ifstream machine_id_file("/etc/machine-id");
        if(machine_id_file.is_open())
        {
            std::string machine_id;
            std::getline(machine_id_file, machine_id);
            machine_id_file.close();

            return machine_id;
        }
        else
        {
            throw std::runtime_error("Error: get machine id");
        }
        return "0";
    }
}