#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

View view;

void getPlayerCoordinateForView(float x, float y) { //функция для считывания координат игрока
	float tempX = x; float tempY = y;

	if (x < 640) tempX = 640;//убираем из вида левую сторону
	if (y < 480) tempY = 480;//верхнюю сторону
	if (y > 2050) tempY = 2220;//нижнюю сторону	
	if (x > 3350) tempX = 3460;//правую сторону	

	view.setCenter(tempX, tempY); //следим за игроком, передавая его координаты. 

}


void viewMap(float time) { //функция для перемещения камеры по карте


	if (Keyboard::isKeyPressed(Keyboard::D)) {
		view.move(0.1 * time, 0);//скроллим карту вправо 
	}

	if (Keyboard::isKeyPressed(Keyboard::S)) {
		view.move(0, 0.1 * time);//вниз
	}

	if (Keyboard::isKeyPressed(Keyboard::A)) {
		view.move(-0.1 * time, 0);//влево
	}
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		view.move(0, -0.1 * time);//вверх
	}

}
