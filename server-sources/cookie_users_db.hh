#ifndef COOKIE_USERS_DB_HH
#define COOKIE_USERS_DB_HH

#include <string>
#include <utility>
#include <iostream>

#include <memory>
#include <pqxx/pqxx>

using namespace pqxx;

namespace net
{
    namespace db
    {
        enum class modify_operation_t
        {
            plus,
            minus
        };

        struct cookie_users_db
        {
            void init_connect();
            void create_users_table();
            void add_users(const std::string &machine_id_value);
            void check_users();
            std::pair<std::string, std::string> get_balance(const std::string &machine_id);
            void delete_users(const std::string &machine_id_value);
            void add_cookie_coin(const std::string &machine_id_value, float add_value, modify_operation_t operation);
            void clear_table();
            int get_row_count();

        private:
            std::unique_ptr<pqxx::connection> conn_obj;
            std::unique_ptr<pqxx::work> work_obj;
        };
    }
}

#endif