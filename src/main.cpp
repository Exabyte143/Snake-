#include <SFML/Graphics.hpp>
#include <Snake/Player.hpp>
#include <Snake/Food.hpp>

/* Defined in Player.cpp */
extern std::string GDirection;

/* Globals */
int WINDOW_SIZE = 540;
int SQUARE_SIZE = 30;
sf::RenderWindow Window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Snake");
Snake::Player player;

int main()
{
    while (Window.isOpen())
    {
        sf::Event event;
        while (Window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                Window.close();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && player.GetDirection() != "DOWN")
            {
                GDirection = "UP";
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && player.GetDirection() != "RIGHT")
            {
                GDirection = "LEFT";
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && player.GetDirection() != "UP" && player.GetDirection() != "N/A")
            {
                GDirection = "DOWN";
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && player.GetDirection() != "LEFT")
            {
                GDirection = "RIGHT";
            }
        }

        player.Move();
        Window.clear();

        bool Collision = player.CheckCollision();

        if (Collision)
        {
            return 0;
        }

        /* DRAW OBJECTS */
        player.Draw();
        Snake::Food::Spawn();
        Window.display();
    }

    return 0;
}