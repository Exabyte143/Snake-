#include <Snake/Player.hpp>
#include <Snake/SnakeSegment.hpp>
#include <iostream>

extern sf::RenderWindow Window;
extern int WINDOW_SIZE;
extern int SQUARE_SIZE;

Snake::Player::Player()
{
    this->Body.push_back(Snake::SnakeSegment(sf::Vector2f((WINDOW_SIZE / 2) - (SQUARE_SIZE / 2), (WINDOW_SIZE / 2) - (SQUARE_SIZE / 2))));
}

void Snake::Player::Move()
{
    for (int i = 0; i < this->Body.size(); i++)
    {
        
    }
}

void Snake::Player::Draw()
{
    for (int i = 0; i < this->Body.size(); i++)
    {
        Window.draw(this->Body[i]);
    }
}