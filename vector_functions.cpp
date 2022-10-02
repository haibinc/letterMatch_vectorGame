//
// Created by Dave R. Smith on 9/8/22.
//
#include "vector_functions.h"

std::vector<std::vector<char>> createArray(int row, int col)
{
    std::vector<std::vector<char>> v(row, std::vector<char>(col, '#'));

    return v;
}

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
    else
    {
        std::cout << "You can not complete the match on an odd puzzle. " << std::endl;
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

void print(std::vector<std::vector<char>> v, std::ofstream& fout, std::string &fileName)
{
    for (int i = 0; i < v.size(); ++i)
    {
        fout << i+1 << ": ";
        std::cout << i+1 << ": ";
        for (int j = 0; j < v[i].size(); ++j)
        {
            fout.width(3);
            std::cout.width(3);
            fout << v[i][j] << std::flush;
            std::cout << v[i][j];
        }
        fout << std::endl;
        std::cout << std::endl;
    }
    fout<< "---------------------------" << std::endl;
    std::cout << "---------------------------" << std::endl;
}

void flipReveal(std::vector<std::vector<char>> &front, std::vector<std::vector<char>> &back, int row, int col)
{
    back[row-1][col-1] = front[row-1][col-1];
}

void update(std::vector<std::vector<char>> &back, int row, int col, char value)
{
    back[row-1][col-1] = value;
}

void getInput(int& row, int &col)
{
    std::cin >> row >> col;
}

void promptInput(int& row, int& col, std::string message)
{
    output(message);
    getInput(row, col);
}

void output(std::string message)
{
    std::cout << message << std::endl;
}

void createFile(std::ofstream &fout, std::string& fileName)
{
    fout.open(fileName);

    if(fout.fail())
    {
        std::cout << "Could not open file";
        exit(1);
    }
}

void closeFile(std::ofstream& fout)
{
    fout.close();
}




