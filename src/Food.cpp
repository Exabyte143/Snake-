#include <Snake/Food.hpp>
#include <Snake/Player.hpp>
#include <iostream>

/* Definition in Main.cpp */
extern int SQUARE_SIZE;
extern int WINDOW_SIZE;
extern sf::RenderWindow Window;
extern Snake::Player player;

/* Globals */
sf::RectangleShape CurrentFood;
bool FoodSpawned = false;

void Snake::Food::Spawn()
{
    if (!FoodSpawned)
    {
        std::vector<Snake::SnakeSegment> Body = player.GetBody();
        CurrentFood = sf::RectangleShape(sf::Vector2f(SQUARE_SIZE, SQUARE_SIZE));
        sf::Vector2f Coords = sf::Vector2f((rand() % WINDOW_SIZE / SQUARE_SIZE) * SQUARE_SIZE, (rand() % WINDOW_SIZE / SQUARE_SIZE) * SQUARE_SIZE);
        for (int i = 0; i < Body.size(); i++)
        {
            if (Coords == Body[i].getPosition())
            {
                return;
            }
        }
        CurrentFood.setPosition(Coords);
        CurrentFood.setFillColor(sf::Color::Red);
        FoodSpawned = true;
    }
    Window.draw(CurrentFood);
}