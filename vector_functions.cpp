//
// Created by Haibin Cao on 9/20/22.
//

#include "vector_functions.h"

std::vector<char> getLetters(int size)
{
    std::vector<char> letters;
    if(size % 2 == 0)
    {

        char a = 'A';
        for(int i=0; i<size/2; i++)
        {
            letters.push_back(a);
            letters.push_back(a++);
        }
    }
    return letters;
}

void shuffle(std::vector<char> &v)
{
    for(int i=0; i<v.size(); i++)
    {
        int idx = rand() % v.size();
        char temp = v[i];
        v[i] = v[idx];
        v[idx] = temp;
    }
}
//fill vector with two of each letter
void fill(std::vector<std::vector<char>> &v)
{
    int size = v.size() * v[0].size();
    std::vector<char> l = getLetters(size);
    shuffle(l);
    int idx = 0;
    for(int i=0; i<v.size(); i++)
    {
        for(int j=0; j<v[i].size(); j++)
        {
            v[i][j] = l[idx++];
        }
    }

}
void print(std::vector<std::vector<char>> v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
        {
            std::cout.width(3);
            std::cout << v[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

std::vector<std::vector<char>> createArray(int row, int col)
{
    std::vector<std::vector<char>> v(row, std::vector<char>(col, '#'));

    return v;
}

void reveal(std::vector<std::vector<char>> &front, std::vector<std::vector<char>> &back, int row, int col)
{
    for(int i=0; i<back.size(); i++)
    {
        for (int j=0; j <back[i].size() ; ++j)
        {
            std::cout.width(3);
            if(i == row && j==col)
            {

                std::cout << front[i][j];
            }
            else
            {
                std::cout << back[i][j];
            }

        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
void update(std::vector<std::vector<char>> &front, std::vector<std::vector<char>> &back, int row, int col)
{
    back[row][col] = front[row][col];
}
void update(std::vector<std::vector<char>> &back, int row, int col, char value)
{
    back[row][col] = value;
}
void getInput(int& row, int &col)
{
    std::cin >> row >> col;
}
//void flip(std::vector<std::vector<char>> v, int row, int col);
//char getInput();
void output(std::string message)
{
    std::cout << message << std::endl;
}
void promptInput(int& row, int& col, std::string message, std::vector<std::vector<char>> &back, std::vector<std::vector<char>> &front)
{
    output(message);
    getInput(row, col);
    update(back, row, col, front[row][col]);
    print(back);
}
//bool isEven(std::vector<std::vector<char>> v);
