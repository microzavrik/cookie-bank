#ifndef cookie_clicker_hxx
#define cookie_clicker_hxx

#include <SFML/Graphics.hpp>

#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>

namespace UI
{
    class CookieClicker
    {
    public:
        CookieClicker(int32_t width, int32_t height);
        void run();
    private:
        sf::RenderWindow window;
        sf::Texture cookie_texture;
        sf::CircleShape cookie;
        sf::Texture background_texture;
        sf::Sprite background_sprite;
        sf::Clock clock;
        float animation_time;
        float animation_duration;
        bool is_animating;
        float scale_multiplier;
        float balance;
        sf::Text balance_text;
        sf::Font font;
    };
}

#endif