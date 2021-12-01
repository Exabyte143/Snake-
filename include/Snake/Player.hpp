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
        std::string GetDirection();
        std::vector<Snake::SnakeSegment> GetBody();
        bool CheckCollision();
        int GetScore();

    private:
        int Score = 0;
        sf::Clock Clock;
        std::vector<Snake::SnakeSegment> Body;
        std::map<std::string, sf::Vector2f> DirectionToVector2f;
        std::string Direction = "N/A";

        void IncreaseScore();
    };
}