#pragma once
#include <SFML/Graphics.hpp>

namespace Snake
{
    class SnakeSegment : public sf::RectangleShape
    {
    public:
        sf::Vector2f PreviousPosition;
        SnakeSegment(sf::Vector2f Position);
    };
}