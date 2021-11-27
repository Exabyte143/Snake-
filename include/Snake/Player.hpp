#pragma once
#include <vector>
#include <Snake/SnakeSegment.hpp>
namespace Snake
{
    class Player
    {
    public:
        Player();
        void Draw();
        void Move();

    private:
        int Score = 0;
        sf::Vector2f Direction;
        std::vector<Snake::SnakeSegment> Body;
    };
}