#include "Game.h"



int main() {
    
    sf::RenderWindow window(sf::VideoMode({SCREEN_WIDTH, SCREEN_HEIGHT}), "p_snake Game");
    sf::Font font("font/pixelmix.ttf") ;
    sf::Clock clock;
    Game g = Game(font, clock) ;

    g.GameLaunch(window);

    

   

    return 0;
}