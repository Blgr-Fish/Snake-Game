#include <iostream>
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Food.h"
#include "Globals.h"
#include <string>



int main() {
    Snake SNAKE ;
    Food FOOD ;

    sf::RenderWindow window(sf::VideoMode({SCREEN_WIDTH, SCREEN_HEIGHT}), "Snake Game");
    sf::Clock clock;
    sf::Font font("font/pixelmix.ttf"); 

    sf::Text scoreText(font);
    sf::Text endText(font);

    scoreText.setCharacterSize(16); 
    scoreText.setFillColor(sf::Color::White);
    scoreText.setStyle(sf::Text::Bold);

    endText.setCharacterSize(40); 
    endText.setFillColor(sf::Color::White);
    endText.setStyle(sf::Text::Bold);

   


    // Boucle principale
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {

            SNAKE.changeDirection();
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (clock.getElapsedTime().asSeconds() > GAME_SPEED) {

                if (SNAKE.checkIsAlive() == true) {
                    SNAKE.move();
                    SNAKE.eat(FOOD);

                    if (FOOD.canEat() == false) {
                        FOOD.createNewFood(SNAKE);
                    }
                } 
                

                clock.restart();
            }

        window.clear(sf::Color::Black); // clear screen 

        SNAKE.draw(window);
        SNAKE.setLastFrameDirection(SNAKE.getDirection());
        FOOD.draw(window);
        std::string print = "Snake: (" + std::to_string(SNAKE.getSnake().front().getX()) + ", " + std::to_string(SNAKE.getSnake().front().getY()) + 
                    ")  Food: (" + std::to_string(FOOD.getX()) + ", " + std::to_string(FOOD.getY()) + ")\nScore : " + std::to_string(SNAKE.getScore());
        scoreText.setString(print);
        window.draw(scoreText);

    
        if(SNAKE.checkIsAlive() == false) {
            endText.setString("YOU LOST !\nTry again!");

            sf::FloatRect textRect = endText.getLocalBounds();
            endText.setOrigin(sf::Vector2f(textRect.position.x + textRect.size.x / 2.f,
                            textRect.position.y + textRect.size.y / 2.f));
            endText.setPosition(sf::Vector2f(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f));
            window.draw(endText);

            
            window.draw(endText);
        }

        


        window.display();
    }

    return 0;
}