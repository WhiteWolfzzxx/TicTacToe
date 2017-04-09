// TicTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ComputerAI.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	//==================INITILIZE=====================//
	//Render Window
	sf::Vector2i screenSize(800, 600);
	sf::RenderWindow window(sf::VideoMode(screenSize.x, screenSize.y), "TicTacToe!");

	//Varables
	const sf::Vector2i ajustmentPosition(160,75);	//Start upper left corner of grid positioning
	const int placementWidth = 180;		//number of pixels between each x grid in vertical and horazontal
	//sf::Vector2i XOPositions[3][3];		//Holds positions of the XO Grid for bounding boxes
	int displayXO[3][3] = { 0 };	// 0 = Display Nothing, 1 = dispaly x, 2 = display O
	sf::Vector2i mousePosition;
	sf::IntRect gridBoundingBoxs[3][3];
	
	//Texture loading
	sf::Texture gameBoardTexture;
	if (!gameBoardTexture.loadFromFile("Textures/GameBoard.png")) { std::cout << "Loading game board texture failed" << std::endl; }
	sf::Texture XTexture;
	if (!XTexture.loadFromFile("Textures/X.png")) { std::cout << "Loading X texture failed" << std::endl; }
	sf::Texture OTexture;
	if (!OTexture.loadFromFile("Textures/O.png")) { std::cout << "Loading O texture failed" << std::endl; }

	//Sprite loading
	sf::Sprite gameBoardSprite(gameBoardTexture);
	sf::Sprite OSprite[3][3];
	sf::Sprite XSprite[3][3];

	//Postion array for sprites and bounding boxes of the game grid
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			//Positions
			//XOPositions[x][y] = sf::Vector2i(ajustmentPosition.x + placementWidth * x, ajustmentPosition.y + placementWidth * y);
			OSprite[x][y].setTexture(OTexture);
			XSprite[x][y].setTexture(XTexture);
			OSprite[x][y].setPosition(ajustmentPosition.x + placementWidth * x, ajustmentPosition.y + placementWidth * y);
			XSprite[x][y].setPosition(ajustmentPosition.x + placementWidth * x, ajustmentPosition.y + placementWidth * y);
			//Bounding Boxs
			gridBoundingBoxs[x][y] = sf::IntRect(sf::Vector2i(ajustmentPosition.x + placementWidth * x, ajustmentPosition.y + placementWidth * y),sf::Vector2i(placementWidth, placementWidth));
		}
	}

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
		mousePosition = sf::Mouse::getPosition(window);	//Sets current mouse position

		//Bounding box collision with mouse
		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				if (gridBoundingBoxs[x][y].contains(mousePosition) && sf::Mouse::isButtonPressed(sf::Mouse::Left) && displayXO[x][y] == 0)
				{
					displayXO[x][y] = 1;	//display x when player clicks in grid location
					easyComputerAI(displayXO);
				}
			}
		}

		

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

		//Draw X's and O's or nothing
		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				if (displayXO[x][y] == 1)
					window.draw(XSprite[x][y]);
				if (displayXO[x][y] == 2)
					window.draw(OSprite[x][y]);
			}
		}

		//example ball
		window.draw(ballSprite);
       
        window.display();
    }

    return 0;
}