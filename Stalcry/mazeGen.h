#pragma once
#include <vector>
#include <iostream>
#include <memory>
#include <random>
using namespace std;

class MazeGenerator
{
public:
    static shared_ptr<vector<vector<char>>> generate(int width, int height)
    {
        if ((width < 1) || (height < 1))
            return nullptr;

        auto topLimit = numeric_limits<int>::max();
        if (((topLimit - 1) / 2 <= width) || ((topLimit - 1) / 2 <= height))
            return nullptr;

        int outputHeight = height * 2 + 1;
        int outputWidth = width * 2 + 1;

        auto maze = make_shared<vector<vector<char>>>();

        maze.get()->reserve(outputHeight);

        for (int i = 0; i < outputHeight; ++i)
        {
            vector<char> row;
            row.reserve(outputWidth);
            for (int j = 0; j < outputWidth; ++j)

                if ((i % 2 == 1) && (j % 2 == 1))
                    row.push_back(' ');
                else
                    if (((i % 2 == 1) && (j % 2 == 0) && (j != 0) && (j != outputWidth - 1)) ||
                        ((j % 2 == 1) && (i % 2 == 0) && (i != 0) && (i != outputHeight - 1)))
                        row.push_back(' ');
                    else
                        row.push_back('0');
            maze.get()->push_back(move(row));
        }
        vector<int> rowSet;
        rowSet.reserve(width);
        for (int i = 0; i < width; ++i)
            rowSet.push_back(0);
        int set = 1;
        random_device rd;
        mt19937 mt(rd());

        uniform_int_distribution<int> dist(0, 2);

        for (int i = 0; i < height; ++i)
        {

            for (int j = 0; j < width; ++j)
                if (rowSet[j] == 0)
                    rowSet[j] = set++;
            for (int j = 0; j < width - 1; ++j)
            {

                const auto rightWall = dist(mt);

                if ((rightWall == 1) || (rowSet[j] == rowSet[j + 1]))
                    maze.get()->at(i * 2 + 1).at(j * 2 + 2) = '0';
                else
                {
                    const auto changingSet = rowSet[j + 1];
                    for (int l = 0; l < width; ++l)
                        if (rowSet[l] == changingSet)
                            rowSet[l] = rowSet[j];
                }
            }
            for (int j = 0; j < width; ++j)
            {
                const auto bottomWall = dist(mt);

                int countCurrentSet = 0;
                for (int l = 0; l < width; ++l)

                    if (rowSet[j] == rowSet[l])
                        countCurrentSet++;

                if ((bottomWall == 1) && (countCurrentSet != 1))
                    maze.get()->at(i * 2 + 2).at(j * 2 + 1) = '0';
            }

            if (i != height - 1)
            {
                for (int j = 0; j < width; ++j) {
                    int countHole = 0;
                    for (int l = 0; l < width; ++l)
                        if ((rowSet[l] == rowSet[j]) && (maze.get()->at(i * 2 + 2).at(l * 2 + 1) == ' '))
                            countHole++;
                    if (countHole == 0)
                        maze.get()->at(i * 2 + 2).at(j * 2 + 1) = ' ';
                }
            }
            if (i != height - 1)
            {
                for (int j = 0; j < width; ++j)
                    if (maze.get()->at(i * 2 + 2).at(j * 2 + 1) == '0')
                        rowSet[j] = 0;
            }

        }

        for (int j = 0; j < width - 1; ++j)
        {
            if (rowSet[j] != rowSet[j + 1])
                maze.get()->at(outputHeight - 2).at(j * 2 + 2) = ' ';
        }

        return maze;
    }

    static void print(const shared_ptr<vector<vector<char>>>& maze, string** map)
    {
        if (maze == nullptr)
            return;
        for (int i = 0; i < maze.get()->size(); ++i)
        {
            for (int j = 0; j < maze.get()->at(0).size(); ++j) {
                map[i][j] = maze.get()->at(i).at(j);
            }
        }
    }
private:
    MazeGenerator() = default;
};