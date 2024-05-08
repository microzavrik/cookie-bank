#include "cookie_clicker.hxx"

int main()
{
    std::cout << "commit test" << std::endl;
    UI::CookieClicker cookie_clicker(800, 600);
    cookie_clicker.run();
    return 1;
}