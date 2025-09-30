#include "Game.h"

Game::Game(sf::Font & font, sf::Clock & clock) {


    this->p_clock = clock ;
    this->p_font = font; 

    

    this->p_sT = new sf::Text(p_font);
    this->p_eT = new sf::Text(p_font);

}

Game::~Game() {
    delete p_sT;
    delete p_eT;
}

void Game::setTexts(sf::Text & sT, sf::Text &  eT) {
    
    sT.setCharacterSize(16); 
    sT.setFillColor(sf::Color::White);
    sT.setStyle(sf::Text::Bold);

    eT.setCharacterSize(40); 
    eT.setFillColor(sf::Color::White);
    eT.setStyle(sf::Text::Bold);
}


void Game::GameLaunch(sf::RenderWindow &window) {

    this->p_snake.resetSnake();
    this->p_food.resetFood();


    

    setTexts(*p_sT,*p_eT);

    

   


    // Boucle principale
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {

            p_snake.changeDirection();
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (p_clock.getElapsedTime().asSeconds() > GAME_SPEED) {

                if (p_snake.checkIsAlive() == true) {
                    p_snake.move();
                    p_snake.eat(p_food);

                    if (p_food.canEat() == false) {
                        p_food.createNewFood(p_snake);
                    }
                } 
                
                p_clock.restart();
            }

        window.clear(sf::Color::Black); // clear screen 

        p_snake.draw(window);
        p_snake.setLastFrameDirection(p_snake.getDirection());
        p_food.draw(window);
        std::string print = "p_snake: (" + std::to_string(p_snake.getSnake().front().getX()) + ", " + std::to_string(p_snake.getSnake().front().getY()) + 
                    ")  p_food: (" + std::to_string(p_food.getX()) + ", " + std::to_string(p_food.getY()) + ")\nScore : " + std::to_string(p_snake.getScore());
        p_sT->setString(print);
        window.draw(*p_sT);

    
        if(p_snake.checkIsAlive() == false) {
            p_eT->setString("YOU LOST !\nTry again! (Press R)");

            sf::FloatRect textRect = p_eT->getLocalBounds();
            p_eT->setOrigin(sf::Vector2f(textRect.position.x + textRect.size.x / 2.f,
                            textRect.position.y + textRect.size.y / 2.f));
            p_eT->setPosition(sf::Vector2f(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f));
            window.draw(*p_eT);

            
            window.draw(*p_eT);


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
                restartGame();
            }
        }

        
        window.display();
    }
    
}

void Game::restartGame() {
    this->p_snake.resetSnake();
    this->p_food.resetFood();
}