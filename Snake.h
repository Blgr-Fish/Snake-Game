#pragma once
#include <deque>
#include "SnakePart.h"
#include <SFML/Graphics.hpp>
#include "Food.h"


class Food; // forward declaration




class Snake {
public:
    
    Snake();
    
    void move();

    void grow();

    void eat(Food& f);

    void setDirection(int direction);

    void changeDirection();

    void draw(sf::RenderWindow& window);

    void checkColisions();

    bool checkIsAlive() ;

    int getScore();

    std::deque<SnakePart> getSnake() const;

    void setLastFrameDirection(int direction) ;
    int getDirection() ;


private:

    int size ;
    bool isAlive ;
    std::deque<SnakePart> snake;
    int direction ; // 1 = Z, 2 = Q, 3 = S, 4 = D -- -1 when not moving
    int score ;

    int lastFrameDirection ;



    
};