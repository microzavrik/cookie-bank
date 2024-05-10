#include "cookie_users_db.hh"

#include <iostream>

using namespace pqxx;

namespace net
{
    namespace db
    {
        void cookie_users_db::create_users_table()
        {
            char *sql;

            try
            {
                /* Create SQL statement */
                sql = "CREATE TABLE COOKIE_USERS ("
                      "ID SERIAL PRIMARY KEY NOT NULL,"
                      "MACHINE_ID TEXT NOT NULL,"
                      "COOKIE_COIN_BALANCE INT NOT NULL);";

                /* Execute SQL query */
                work_obj->exec(sql);
                // work_obj->commit();
                std::cout << "Table created successfully" << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << std::endl;
                return;
            }

            return;
        }

        void cookie_users_db::add_users(const std::string &machine_id_value)
        {
            char sql[128]; // Assuming a fixed size for the SQL statement

            try
            {
                /* Create SQL statement */
                std::sprintf(sql, "INSERT INTO COOKIE_USERS (MACHINE_ID, COOKIE_COIN_BALANCE) VALUES ('%s', %d)", machine_id_value.c_str(), 0);

                /* Execute SQL query */
                work_obj->exec(sql);
                // work_obj->commit();
                std::cout << "New user added successfully" << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << std::endl;
                return;
            }
        }

        void cookie_users_db::check_users()
        {
            try
            {
                /* Create SQL statement to select all users */
                std::string sql = "SELECT * FROM COOKIE_USERS;";

                /* Create a non-transactional object */
                nontransaction N(*conn_obj);

                /* Execute SQL query */
                result R(N.exec(sql));

                /* List down all the records */
                for (result::const_iterator c = R.begin(); c != R.end(); ++c)
                {
                    std::cout << "ID = " << c[0].as<int>() << " | ";
                    std::cout << "MID = " << c[1].as<std::string>() << " | ";
                    std::cout << "C$ = " << c[2].as<std::string>() << std::endl;
                }

                // work_obj->commit();
                std::cout << "Users checked successfully" << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << std::endl;
                return;
            }
        }

        std::pair<std::string, std::string> cookie_users_db::get_balance(const std::string &machine_id)
        {
            try
            {
                /* Create SQL statement */
                std::string sql = "SELECT MACHINE_ID, COOKIE_COIN_BALANCE FROM COOKIE_USERS WHERE MACHINE_ID = '" + machine_id + "';";

                /* Create a non-transactional object */
                nontransaction N(*conn_obj);

                /* Execute SQL query */
                result R(N.exec(sql));

                /* Check if the query returned any results */
                if (!R.empty())
                {
                    /* Get the first row of the result */
                    row row_obj = R[0];

                    /* Extract the MACHINE_ID and COOKIE_COIN_BALANCE values */
                    std::string machine_id_value = row_obj[0].as<std::string>();
                    std::string cookie_coin_balance = row_obj[1].as<std::string>();

                    work_obj->commit();
                    return std::make_pair(machine_id_value, cookie_coin_balance);
                }
                else
                {
                    // work_obj->commit();
                    return std::make_pair("", "");
                }
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << std::endl;
                return std::make_pair("", "");
            }
        }

        void cookie_users_db::delete_users(const std::string &machine_id_value)
        {
            try
            {
                /* Create SQL statement to delete user by MACHINE_ID */
                std::string sql = "DELETE FROM COOKIE_USERS WHERE MACHINE_ID = '" + machine_id_value + "';";

                /* Execute SQL query */
                work_obj->exec(sql);
                // work_obj->commit();
                std::cout << "User with MACHINE_ID " << machine_id_value << " deleted successfully" << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << std::endl;
                return;
            }
        }

        void cookie_users_db::add_cookie_coin(const std::string &machine_id_value, float add_value, modify_operation_t operation)
        {
            try
            {
                /* Determine the operation to perform */
                std::string operation_str = (operation == modify_operation_t::plus) ? "+" : "-";

                /* Create SQL statement to update COOKIE_COIN_BALANCE */
                std::string sql = "UPDATE COOKIE_USERS SET COOKIE_COIN_BALANCE = COOKIE_COIN_BALANCE " + operation_str + " " + std::to_string(add_value) + " WHERE MACHINE_ID = '" + machine_id_value + "';";

                /* Execute SQL query */
                work_obj->exec(sql);
                work_obj->commit();

                std::cout << "COOKIE_COIN_BALANCE updated successfully for MACHINE_ID " << machine_id_value << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << std::endl;
                return;
            }
        }

        void cookie_users_db::clear_table()
        {
            try
            {
                /* Create SQL statement to delete all rows from the table */
                std::string sql = "TRUNCATE TABLE COOKIE_USERS;";

                /* Execute SQL query */
                work_obj->exec(sql);
                work_obj->commit();

                std::cout << "Table COOKIE_USERS cleared successfully" << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << std::endl;
                return;
            }
        }

        void cookie_users_db::init_connect()
        {
            std::cout << "Constructor" << std::endl;

            try
            {
                conn_obj = std::make_unique<pqxx::connection>(connection("dbname = users user = postgres password = cohondob hostaddr = 127.0.0.1 port = 5432"));

                if (conn_obj->is_open())
                {
                    std::cout << "Opened database successfully: " << conn_obj->dbname() << std::endl;

                    // Assign conn_obj to work_obj
                    work_obj = std::make_unique<pqxx::work>(*conn_obj);

                    // work_obj->commit();
                }
                else
                {
                    std::cout << "Can't open database" << std::endl;
                    // Handle the case where the connection couldn't be established
                }
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << std::endl;
                // Handle any exceptions that occur during connection setup
            }
        }

        int cookie_users_db::get_row_count()
        {
            try
            {
                work_obj->commit();
                /* Create SQL statement to count the number of rows */
                std::string sql = "SELECT COUNT(*) FROM COOKIE_USERS;";

                /* Create a non-transactional object */
                nontransaction N(*conn_obj);

                /* Execute SQL query */
                result R(N.exec(sql));

                /* Get the count value from the result */
                int row_count = R[0][0].as<int>();

                work_obj->commit();
                return row_count;
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << std::endl;
                return -1; // Return -1 on error
            }
        }

    }
}