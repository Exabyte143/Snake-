#include <Snake/Player.hpp>
#include <Snake/SnakeSegment.hpp>
#include <map>

/* Main.cpp Definitions */
extern sf::RenderWindow Window;
extern int WINDOW_SIZE;
extern int SQUARE_SIZE;

/* Food.cpp Definitions */
extern sf::RectangleShape CurrentFood;
extern bool FoodSpawned;

/* Globals */
std::string GDirection = "N/A";

Snake::Player::Player()
{
    this->Body.push_back(Snake::SnakeSegment(sf::Vector2f((WINDOW_SIZE / 2) - (SQUARE_SIZE), (WINDOW_SIZE / 2) - (SQUARE_SIZE))));
    this->Body.push_back(Snake::SnakeSegment(this->Body[0].getPosition() + sf::Vector2f(0, SQUARE_SIZE)));
    this->Body.push_back(Snake::SnakeSegment(this->Body[1].getPosition() + sf::Vector2f(0, SQUARE_SIZE)));

    this->DirectionToVector2f.insert(std::pair<std::string, sf::Vector2f>("N/A", sf::Vector2f(0, 0)));
    this->DirectionToVector2f.insert(std::pair<std::string, sf::Vector2f>("UP", sf::Vector2f(0, -SQUARE_SIZE)));
    this->DirectionToVector2f.insert(std::pair<std::string, sf::Vector2f>("DOWN", sf::Vector2f(0, SQUARE_SIZE)));
    this->DirectionToVector2f.insert(std::pair<std::string, sf::Vector2f>("LEFT", sf::Vector2f(-SQUARE_SIZE, 0)));
    this->DirectionToVector2f.insert(std::pair<std::string, sf::Vector2f>("RIGHT", sf::Vector2f(SQUARE_SIZE, 0)));
}

void Snake::Player::Move()
{
    if (this->Clock.getElapsedTime().asMilliseconds() > 250 && GDirection != "N/A")
    {

        this->Direction = GDirection;
        for (int i = 0; i < this->Body.size(); i++)
        {
            Body[i].PreviousPosition = Body[i].getPosition();
            if (i == 0)
            {
                Body[i].setPosition(Body[i].getPosition() + this->DirectionToVector2f[this->Direction]);
            }
            else
            {
                Body[i].setPosition(Body[i - 1].PreviousPosition);
            }
        }
        this->Clock.restart();
    }
}

void Snake::Player::Draw()
{
    for (int i = 0; i < this->Body.size(); i++)
    {
        Window.draw(this->Body[i]);
    }
}

void Snake::Player::IncreaseScore()
{
    sf::Vector2f PositionDifference = this->Body[Body.size() - 1].getPosition() - this->Body[Body.size() - 2].getPosition();

    if (PositionDifference == this->DirectionToVector2f["UP"])
    {
        this->Body.push_back(Snake::SnakeSegment(Body[Body.size()].getPosition() - DirectionToVector2f["UP"]));
    }
    else if (PositionDifference == this->DirectionToVector2f["DOWN"])
    {
        this->Body.push_back(Snake::SnakeSegment(Body[Body.size()].getPosition() - DirectionToVector2f["DOWN"]));
    }
    else if (PositionDifference == this->DirectionToVector2f["LEFT"])
    {
        this->Body.push_back(Snake::SnakeSegment(Body[Body.size()].getPosition() - DirectionToVector2f["LEFT"]));
    }
    else if (PositionDifference == this->DirectionToVector2f["RIGHT"])
    {
        this->Body.push_back(Snake::SnakeSegment(Body[Body.size()].getPosition() - DirectionToVector2f["RIGHT"]));
    }
    FoodSpawned = false;
    this->Score++;
}

std::string Snake::Player::GetDirection()
{
    return this->Direction;
}

std::vector<Snake::SnakeSegment> Snake::Player::GetBody()
{
    return this->Body;
}

bool Snake::Player::CheckCollision()
{
    sf::Vector2f HeadPos = this->Body[0].getPosition();
    if (HeadPos == CurrentFood.getPosition())
    {
        this->IncreaseScore();
        return false;
    }
    else if (HeadPos.x == WINDOW_SIZE || HeadPos.y == WINDOW_SIZE || HeadPos.x == -SQUARE_SIZE || HeadPos.y == -SQUARE_SIZE)
    {
        return true;
    }
    else
    {
        for (int i = 0; i < this->Body.size(); i++)
        {
            if (Body[i].getPosition() == Body[0].getPosition() && i > 0)
            {
                return true;
            }
        }
    }
    return false;
}

int Snake::Player::GetScore()
{
    return Score;
}