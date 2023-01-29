#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

View view;

void getPlayerCoordinateForView(float x, float y) { //������� ��� ���������� ��������� ������
	float tempX = x; float tempY = y;

	if (x < 640) tempX = 640;//������� �� ���� ����� �������
	if (y < 480) tempY = 480;//������� �������
	if (y > 2050) tempY = 2220;//������ �������	
	if (x > 3350) tempX = 3460;//������ �������	

	view.setCenter(tempX, tempY); //������ �� �������, ��������� ��� ����������. 

}


void viewMap(float time) { //������� ��� ����������� ������ �� �����


	if (Keyboard::isKeyPressed(Keyboard::D)) {
		view.move(0.1 * time, 0);//�������� ����� ������ 
	}

	if (Keyboard::isKeyPressed(Keyboard::S)) {
		view.move(0, 0.1 * time);//����
	}

	if (Keyboard::isKeyPressed(Keyboard::A)) {
		view.move(-0.1 * time, 0);//�����
	}
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		view.move(0, -0.1 * time);//�����
	}

}
