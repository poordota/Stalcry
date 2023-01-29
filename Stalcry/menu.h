#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "view.h"
#include "map.h"
#include "audio.h"

using namespace sf;

int po = 0;
void menu(RenderWindow& window, float x, float y, bool& finalLevel, int point) {
	
	Texture menuTexture1, menuTexture2, menuTexture3, menuBackground, menuTexture4, menuTexture4_1;
	menuTexture1.loadFromFile("images/menuPlay.png");
	menuTexture2.loadFromFile("images/menuInfo.png");
	menuTexture3.loadFromFile("images/menuExit.png");
	menuTexture4.loadFromFile("images/menuFinal.png");
	menuTexture4_1.loadFromFile("images/menuFinalBlack2.png");
	menuBackground.loadFromFile("images/menuBG.jpg");
	Sprite menuPlay(menuTexture1), menuInfo(menuTexture2), menuExit(menuTexture3), menuFinal(menuTexture4), 
		menuBg(menuBackground), menuFinalBlack(menuTexture4_1);
	
	auto color1 = Color(225, 159, 81);
	Font font1;
	font1.loadFromFile("fonts/DS Pixel Cyr Regular.ttf");
	Text textInfo("", font1, 45);
	textInfo.setFillColor(color1);
	
	po += point;
	std::ostringstream PointsString;
	PointsString << po;
	
	
	bool isMenu = 1;
	int menuNum = 0;

	menuPlay.setPosition(x-640+490, y-480+520);
	menuExit.setPosition(x-640+490, y-480+670);
	menuInfo.setPosition(x-640+140, y-480+557);
	menuFinal.setPosition(x-640+840, y-480+557);
	menuFinalBlack.setPosition(x-640+840, y-480+557);
	menuBg.setPosition(x-640, y-480);
	/////////////////ÌÅÍÞ///////////////////
	while (isMenu)
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				//DeleteMap();
				window.close();
		}

		menuPlay.setColor(Color::White);
		menuExit.setColor(Color::White);
		menuFinal.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(129, 181, 221));
	    if (IntRect(490, 520, 300, 119).contains(Mouse::getPosition(window))) { 
			menuPlay.setColor(Color::Green); 
			menuNum = 1; 
		}
		if (IntRect(490, 670, 300, 119).contains(Mouse::getPosition(window))) { 
			menuExit.setColor(Color::Green); 
			menuNum = 2; 
		}
		if (IntRect(840, 557, 300, 190).contains(Mouse::getPosition(window))) { 
			if (po >= 7000) {
				menuFinal.setColor(Color::Green);
				menuNum = 3;
			}
		}

		

		textInfo.setString(L"Î÷êè:\n" + PointsString.str());
		textInfo.setPosition(x - 640 + 185, y - 480 + 592);

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) { 
				pressAudio();
				isMenu = false;
			}
			if (menuNum == 2) {  
				//DeleteMap();
				pressAudio();
				window.close(); 
				isMenu = false; 
			}
			if (menuNum == 3) { 
				pressAudio();
				for (int i = 0; i < HEIGHT_MAP; i++) {
					for (int j = 0; j < WIDTH_MAP; j++)
						TileMap[i][j] = ' ';
				}
				isMenu = false;  
				finalLevel = true; 
			}
		}

		
		window.draw(menuBg);
		window.draw(menuPlay);
		window.draw(menuExit);
		window.draw(menuFinalBlack);
		if(po>7000) window.draw(menuFinal);
		window.draw(menuInfo);
		window.draw(textInfo);
		window.display();
	}
}
