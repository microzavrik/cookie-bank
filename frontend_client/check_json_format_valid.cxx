#include "check_json_format_valid.hxx"

#include <nlohmann/json.hpp>

namespace utils
{
    bool check_json_format_valid(const std::string& data, types::PacketType check_type)
    {
        nlohmann::json json(data);

        switch(check_type)
        {
            case types::PacketType::Login:
            {
                try
                {
                    auto json_data = nlohmann::json::parse(data);

                    if(json_data.contains("machine_id")) 
                    {
                        return true;
                    }
                    return false;
                }
                catch(const nlohmann::json::parse_error& e)
                {
                    return false;
                }
            }
            default:
                return false;
        }
    }
}