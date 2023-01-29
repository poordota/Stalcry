#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "mazeGen.h"
using namespace sf;

const int HEIGHT_MAP = 27;//размер карты высота
const int WIDTH_MAP = 41;//размер карты ширина 



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
    int randomElementX = 0;//случайный элемент по горизонтали
    int randomElementY = 0;//случ эл-т по вертикали
    srand(time(0));//рандом	
    int countCrystals = 30;//количество кристаллов
    int countHearts = 1;
    while (countCrystals > 0) {
        randomElementX = 1 + rand() % (WIDTH_MAP - 1);//рандомное по иксу от 1 до ширина карты-1, чтобы не получать числа бордюра карты
        randomElementY = 1 + rand() % (HEIGHT_MAP - 1);//по игреку так же
        if (TileMap[randomElementY][randomElementX] == ' ') {//если встретили символ пробел, 
            TileMap[randomElementY][randomElementX] = '1'; //то ставим туда камень.
            
            countCrystals--;
        }
    }
    
    TileMap[1][1] = ' ';
    TileMap[25][39] = 'w';
}


