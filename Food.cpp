#include "Globals.h"
#include "Food.h"
#include "Snake.h"
#include <deque>
#include <random>
#include <iostream>


Food::Food() {
    this->p_x = 0;
    this->p_y = 0;
    this->isVisible = false ;
}

void Food::resetFood() {
    this->p_x = 0;
    this->p_y = 0;
    this->isVisible = false ;
}

void Food::draw(sf::RenderWindow& window) {
    if (!isVisible) return;
    sf::RectangleShape shape(sf::Vector2f(SNAKE_PART_SIZE, SNAKE_PART_SIZE));
    shape.setFillColor(sf::Color::Red);

    float x = p_x * SNAKE_PART_SIZE;
    float y = p_y * SNAKE_PART_SIZE;

    shape.setPosition(sf::Vector2f(x,y));

    window.draw(shape);
}

void Food::createNewFood(const Snake &snake){
    bool isValidPlacement = false;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribX(0, (SCREEN_WIDTH / SNAKE_PART_SIZE) - 1);
    std::uniform_int_distribution<> distribY(0, (SCREEN_HEIGHT / SNAKE_PART_SIZE) - 1);

    int x;
    int y;
    std::deque<SnakePart> snakeQueue = snake.getSnake() ;


    do {
        
        x = distribX(gen);
        y = distribY(gen);

        bool isInSnake = false ;

        // Check if is in bound
        if (x >= 0 && x < SCREEN_WIDTH / SNAKE_PART_SIZE &&
            y >= 0 && y < SCREEN_HEIGHT / SNAKE_PART_SIZE) {
        
            // Now check if is not in snake :
            for (SnakePart s : snakeQueue) {
                if (x == s.getX() && y == s.getY()){
                    isInSnake = true ;
                    break;
                }
            }
            
            if (isInSnake == false) {
                isValidPlacement = true ;
            }
        }
    } while(!isValidPlacement);

    this->p_x = x;
    this->p_y = y;
    this->setVisibility(true);

    std::cout << "Food created at pos (x,y) : (" << p_x<<","<<p_y<< ") !" <<std::endl;
    
}

bool Food::canEat() const { return isVisible ;}

int Food::getX() const { return this->p_x ;}
int Food::getY()const  { return this->p_y ;}

void Food::setVisibility(bool v) {this->isVisible = v ;}