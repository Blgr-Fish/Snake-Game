#pragma once
#include "Globals.h"
#include "Snake.h"
class Snake; // forward declaration


class Food {
    public:
        Food();

        void createNewFood(const Snake& snake);
        void draw(sf::RenderWindow& window);
        bool canEat() const;

        int getX()const ;
        int getY() const ;

        void setVisibility( bool v) ;

        void resetFood();
    private:
        int p_x;
        int p_y;
        bool isVisible ;
};