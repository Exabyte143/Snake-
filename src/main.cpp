#include <SFML/Graphics.hpp>
#include "Snake/Player.hpp"
#include "Snake/Food.hpp"
#include "Fonts/NotoSans-Regular.h"

/* Defined in Player.cpp */
extern std::string GDirection;

/* Globals */
int WINDOW_SIZE = 540;
int SQUARE_SIZE = 30;
bool IsGameEnded = false;
sf::RenderWindow Window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Snake");
Snake::Player player;

int main()
{
    /* Text */
    sf::Font Font;
    Font.loadFromMemory(NotoSans_Regular_ttf, NotoSans_Regular_ttf_len);
    sf::Text Text("Press W, A, or D To Start", Font);
    Text.setOrigin(sf::Vector2f(Text.getScale().x / 2, Text.getScale().y / 2));
    Text.setPosition(sf::Vector2f(0, 0));

    while (Window.isOpen())
    {
        sf::Event event;
        while (Window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                Window.close();
            }
            if (!IsGameEnded)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && player.GetDirection() != "DOWN")
                {
                    GDirection = "UP";
                    Text.setString("");
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && player.GetDirection() != "RIGHT")
                {
                    GDirection = "LEFT";
                    Text.setString("");
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && player.GetDirection() != "UP" && player.GetDirection() != "N/A")
                {
                    GDirection = "DOWN";
                    Text.setString("");
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && player.GetDirection() != "LEFT")
                {
                    GDirection = "RIGHT";
                    Text.setString("");
                }
            }
        }

        player.Move();
        Window.clear();

        bool Collision = player.CheckCollision();

        if (Collision)
        {
            IsGameEnded = true;
            Text.setString("You lose! Your score was " + std::to_string(player.GetScore()));
            GDirection = "N/A";
        }

        /* DRAW OBJECTS */
        player.Draw();
        Snake::Food::Spawn();
        Window.draw(Text);

        Window.display();
    }

    return 0;
}