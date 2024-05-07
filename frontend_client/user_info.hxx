#ifndef user_info_hxx
#define user_info_hxx

#include <string>

namespace network
{
    struct user_info
    {
        void instance();
    private:
        std::string machine_id;
    };
}

#endif