#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "mazeGen.h"
using namespace sf;

const int HEIGHT_MAP = 27;//������ ����� ������
const int WIDTH_MAP = 41;//������ ����� ������ 



String FinalMap[HEIGHT_MAP] = {
    "ttttttttttttttttttttttttttttttttttttttttt",
    "ttlrttttttttttttttttttttttttttttttttttttt",
    "ttlrttttttttttttttttttttttttttttttttttttt",
    "ttlrttttttttttttttttttttttttttttttttttttt",
    "ttlrttttttttttttttttttttttttttttttttttttt",
    "ttlrttttttttttttttttttttttttttttttttttttt",
    "ttlrttttttttttttttttttttttttttttttttttttt",
    "ttlrttttttttttttttttttttttttttttttttttttt",
    "ttlrttttttttttttttttttttttttttttttttttttt",
    "ttlguuuuuyttttttttttttttttttttttttttttttt",
    "tthdddddgrttttttttttttttttttttttttttttttt",
    "ttttttttlrtttttttttttootttttttttttttttttt",
    "ttttttttlrtttttttttttlrtttttttttttttttttt",
    "ttttttttlrtttttttttttlrtttttttttttttttttt",
    "ttttttttlrtttttttttkugguuyttttttttttttttt",
    "ttttttttlguuuuuunuugggggggytttttttttttttt",
    "tttttttthdddddddmdddddddddftttttttttttttt",
    "ttttttttttttttttttttttttttttttttttttttttt",
    "ttttttttttttttttttttttttttttttttttttttttt",
    "ttttttttttttttttttttttttttttttttttttttttt",
    "ttttttttttttttttttttttttttttttttttttttttt",
    "ttttttttttttttttttttttttttttttttttttttttt",
    "ttttttttttttttttttttttttttttttttttttttttt",
    "ttttttttttttttttttttttttttttttttttttttttt",
    "ttttttttttttttttttttttttttttttttttttttttt",
    "ttttttttttttttttttttttttttttttttttttttttt",
    "ttttttttttttttttttttttttttttttttttttttttt",
};


string** TileMap = new string * [HEIGHT_MAP];

void GenerateMap() {
    for (int i = 0; i < HEIGHT_MAP; i++)
        TileMap[i] = new string[WIDTH_MAP];
}
void DeleteMap() {
    for (int i = 0; i < HEIGHT_MAP; i++)
        delete[] TileMap[i];
    delete[] TileMap;
}

void randomMapGenerate() //
{ 
    MazeGenerator::print(MazeGenerator::generate((WIDTH_MAP - 1) / 2, (HEIGHT_MAP - 1) / 2), TileMap);
    int randomElementX = 0;//��������� ������� �� �����������
    int randomElementY = 0;//���� ��-� �� ���������
    srand(time(0));//������	
    int countCrystals = 30;//���������� ����������
    int countHearts = 1;
    while (countCrystals > 0) {
        randomElementX = 1 + rand() % (WIDTH_MAP - 1);//��������� �� ���� �� 1 �� ������ �����-1, ����� �� �������� ����� ������� �����
        randomElementY = 1 + rand() % (HEIGHT_MAP - 1);//�� ������ ��� ��
        if (TileMap[randomElementY][randomElementX] == ' ') {//���� ��������� ������ ������, 
            TileMap[randomElementY][randomElementX] = '1'; //�� ������ ���� ������.
            
            countCrystals--;
        }
    }
    
    TileMap[1][1] = ' ';
    TileMap[25][39] = 'w';
}


