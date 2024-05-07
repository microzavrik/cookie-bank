#include "cookie_clicker.hxx"

namespace UI
{
    CookieClicker::CookieClicker(int32_t width, int32_t height) : window(sf::VideoMode(width, height), "Cookie Clicker")
    {
        cookie_texture.loadFromFile("./resources/cookie_texture.png");

        cookie.setRadius(100);
        cookie.setTexture(&cookie_texture);
        cookie.setOrigin(cookie.getRadius(), cookie.getRadius());
        cookie.setPosition(window.getSize().x / 2, window.getSize().y / 2);

        background_texture.loadFromFile("./resources/background.png");
        background_sprite.setTexture(background_texture);

        animation_time = 0.0f;
        animation_duration = 0.1f;
        is_animating = false;
        scale_multiplier = 1.2f;
        balance = {};

        font.loadFromFile("/usr/share/fonts/TTF/DejaVuSans.ttf");
        balance_text.setFont(font);
        balance_text.setCharacterSize(24);
        balance_text.setFillColor(sf::Color::White);
        balance_text.setPosition(10, 10);
    }

    void CookieClicker::run()
    {
        while(window.isOpen())
        {
            sf::Event event;
            while(window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                    window.close();
                if(event.type == sf::Event::MouseButtonPressed)
                {
                    if(event.mouseButton.button == sf::Mouse::Left)
                    {
                        sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                        if(cookie.getGlobalBounds().contains(mouse_pos))
                        {
                            float click_value = 0.1f + static_cast<float>(rand()) / static_cast<float>(RAND_MAX/(0.4f - 0.1f));
                            balance += click_value;
                            is_animating = true;
                            clock.restart();
                        }
                    }
                }
            }

            if(is_animating)
            {
                animation_time = clock.getElapsedTime().asSeconds();
                if(animation_time >= animation_duration)
                {
                    is_animating = false;
                    animation_time = 0.0f;
                }
                cookie.setScale(scale_multiplier - (animation_time / animation_duration) * (scale_multiplier - 1.0f), 
                                scale_multiplier - (animation_time / animation_duration) * (scale_multiplier - 1.0f));
            }
            else
            {
                cookie.setScale(1.0f, 1.0f);
            }

            std::ostringstream balance_stream;
            balance_stream << "Balance: " << balance;
            balance_text.setString(balance_stream.str());

            window.clear();
            window.draw(background_sprite);
            window.draw(cookie);
            window.draw(balance_text);
            window.display();
        }
    }
}