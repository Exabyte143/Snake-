#include <SFML/Graphics.hpp>
#include <Snake/SnakeSegment.hpp>

extern int SQUARE_SIZE;

Snake::SnakeSegment::SnakeSegment(sf::Vector2f Position)
{
    this->setSize(sf::Vector2f(SQUARE_SIZE, SQUARE_SIZE));
    this->setPosition(Position);
    this->setFillColor(sf::Color::Green);
}