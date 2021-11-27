#pragma once
#include <vector>
#include <Snake/SnakeSegment.hpp>
#include <map>
#include <SFML/Graphics.hpp>

namespace Snake
{
    class Player
    {
    public:
        Player();
        void Draw();
        void Move();
        void IncreaseScore();
        std::string GetDirection();

    private:
        int Score = 0;
        sf::Clock Clock;
        std::vector<Snake::SnakeSegment> Body;
        std::map<std::string, sf::Vector2f> DirectionToVector2f;
        std::string Direction = "N/A";
    };
}