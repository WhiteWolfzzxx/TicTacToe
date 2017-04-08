// TicTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	//==================INITILIZE=====================//
	sf::Vector2i screenSize(800, 600);
	sf::RenderWindow window(sf::VideoMode(screenSize.x,screenSize.y), "TicTacToe!");
	//Texture loading
	sf::Texture gameBoardTexture;
	if (!gameBoardTexture.loadFromFile("Textures/GameBoard.png")) { std::cout << "Loading game board texture failed" << std::endl;  }
	
	//Sprite loading
	sf::Sprite gameBoardSprite(gameBoardTexture);

	//Example ball experiment
	sf::Texture ballTexture;
	sf::Sprite ballSprite;
	sf::Vector2f ballVelocity;
	if (!ballTexture.loadFromFile("Textures/Ball.png"))
	{
		std::cout << "Loading ball texture failed" << std::endl;
	}
	ballSprite.setTexture(ballTexture);
	//==================GAME UPDATE=====================//
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) { if (event.type == sf::Event::Closed) window.close(); }
		//Update stuff here


#pragma region BallUpdate
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			ballVelocity.x += 0.001;
			//ballSprite.move(sf::Vector2f(0.1, 0));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			ballVelocity.x -= 0.001;
			//ballSprite.move(sf::Vector2f(-0.1, 0));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			ballVelocity.y += 0.001;
			//ballSprite.move(sf::Vector2f(0, 0.1));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			ballVelocity.y -= 0.001;
			//ballSprite.move(sf::Vector2f(0, -0.1));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			ballVelocity = sf::Vector2f(0,0);

		if (ballSprite.getPosition().x < 0)
			ballVelocity = sf::Vector2f(-ballVelocity.x, ballVelocity.y);
		if (ballSprite.getPosition().x > screenSize.x)
			ballVelocity = sf::Vector2f(-ballVelocity.x, ballVelocity.y);
		if (ballSprite.getPosition().y < 0)
			ballVelocity = sf::Vector2f(ballVelocity.x, -ballVelocity.y);
		if (ballSprite.getPosition().y > screenSize.y)
			ballVelocity = sf::Vector2f(ballVelocity.x, -ballVelocity.y);
		ballSprite.move(ballVelocity);
#pragma endregion
	//==================GAME DRAW=====================//
        window.clear();
		//Draw stuff here
		window.draw(gameBoardSprite);

		//example ball
		window.draw(ballSprite);
       
        window.display();
    }

    return 0;
}