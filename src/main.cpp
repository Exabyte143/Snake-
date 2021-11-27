#include <SFML/Graphics.hpp>
#include <Snake/Player.hpp>

/* Globals */
int WINDOW_SIZE = 540;
int SQUARE_SIZE = 30;
sf::RenderWindow Window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Snake");

static Snake::Player player;
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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            {
                printf("W has been pressed\n");
            }
        }

        Window.clear();
        player.Draw();
        Window.display();
    }

    return 0;
}