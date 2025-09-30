#pragma once
#include "Snake.h"
#include "Food.h"

class Game {
public:
     Game(sf::Font & font, sf::Clock & clock);
     ~Game();
     
     
     void GameLaunch(sf::RenderWindow & window);

     void setTexts(sf::Text & sT, sf::Text &  eT);

     void restartGame();

private:
    Snake p_snake;
    Food p_food;
    sf::Font p_font;

    sf::Clock p_clock ;

    sf::Text *p_sT ;
    sf::Text *p_eT ;

};