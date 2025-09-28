#include "Snake.h"
#include "Globals.h"
#include <iostream>

Snake::Snake() {

    this->size = 1 ;

    this->isAlive = true ;

    this->snake.push_back(SnakePart((SCREEN_WIDTH/SNAKE_PART_SIZE)/2,(SCREEN_HEIGHT/SNAKE_PART_SIZE)/2));

    this->direction = -1 ;

    this->score = 0 ;

    this->lastFrameDirection = -1 ;



}

int Snake::getDirection() {return this->direction;}

void Snake::setLastFrameDirection(int direction) { this->lastFrameDirection = direction ;}

bool Snake::checkIsAlive(){ return this->isAlive ;} 

void Snake::changeDirection() {
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z) ||
         sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) && this->lastFrameDirection !=3)
        {
            this->direction = 1 ;
        }
    else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q) ||
              sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))  && this->lastFrameDirection !=4)
        {
            this->direction = 2 ;
        }
    else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) ||
              sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))  && this->lastFrameDirection !=1)
        {
            this->direction = 3 ;
        }
    else  if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) ||
               sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) && this->lastFrameDirection !=2)
        {
            this->direction = 4 ;   
        }

    else {
            this->direction = direction ;
    }
}

void Snake::move() {

    

    SnakePart head = this->snake.front();
    std::cout << "X : " <<head.getX() << ", Y : " << head.getY() << std::endl;

    
    if (this->direction == 1 )
        {

            this->snake.front().setHead(false);
            this->snake.push_front(SnakePart(head.getX(),head.getY()-1));
            this->snake.pop_back();

        }
    else if (this->direction == 2 )
        {

            this->snake.front().setHead(false);
            this->snake.push_front(SnakePart(head.getX()-1,head.getY()));
            this->snake.pop_back();

        }
    else if (this->direction == 3)
        {

            this->snake.front().setHead(false);
            this->snake.push_front(SnakePart(head.getX(),head.getY()+1));
            this->snake.pop_back();
        }
    else  if (this->direction == 4)
        {

            this->snake.front().setHead(false);
            this->snake.push_front(SnakePart(head.getX()+1,head.getY()));
            this->snake.pop_back();
        }

       checkColisions();
}

void Snake::checkColisions() {
        SnakePart head = this->snake.front();

        // Out of bounds
        if (head.getX() < 0 || head.getX() >= SCREEN_WIDTH / SNAKE_PART_SIZE ||
        head.getY() < 0 || head.getY() >= SCREEN_HEIGHT / SNAKE_PART_SIZE) {

            this->isAlive = false ;
        
        }

        for (SnakePart s : snake) {
            if (!s.isHead() && head.getX() == s.getX() && head.getY() == s.getY()){
                this->isAlive = false ;
            }
        }

        
}

void Snake::setDirection(int direction) {
    this->direction = direction ;
}

void Snake::draw(sf::RenderWindow& window) {
    for (SnakePart part : snake) {

        float x = part.getX() * SNAKE_PART_SIZE;
        float y = part.getY() * SNAKE_PART_SIZE;

        sf::RectangleShape shape(sf::Vector2f(SNAKE_PART_SIZE, SNAKE_PART_SIZE));
        shape.setFillColor(sf::Color (0,200,100));
        shape.setPosition(sf::Vector2f(x,y));
        window.draw(shape);
    }
}

std::deque<SnakePart> Snake::getSnake() const {return this->snake ;}

void Snake::eat(Food& f) {

    
    SnakePart head = this->snake.front();

    // eat the food
    if (head.getX() == f.getX() && head.getY() == f.getY() && f.canEat()) {
        f.setVisibility(false);
        f.createNewFood(*this);
        
        score++ ;
        std::cout << "score : " << score << std::endl ;
        grow();
    }
}

void Snake::grow(){

    
    this->snake.push_back(SnakePart(snake.back().getX(),snake.back().getY()));

}

int Snake::getScore(){ return this->score ;}