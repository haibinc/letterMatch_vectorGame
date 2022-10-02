//
// Created by Haibin Cao on 9/20/22.
//

#ifndef MATCHINGPUZZLE_VECTOR_FUNCTIONS_H
#define MATCHINGPUZZLE_VECTOR_FUNCTIONS_H
#include <vector>
#include <iostream>
#include <fstream>

void createFile(std::ofstream& fout, std::string& fileName);
void closeFile(std::ofstream& fout);
void shuffle(std::vector<char> &v);
std::vector<char> getLetters(int size);
void fill(std::vector<std::vector<char>> &v);
std::vector<std::vector<char>> createArray(int row, int col);
void print(std::vector<std::vector<char>> v, std::ofstream& fout, std::string& fileName);
void flip(std::vector<std::vector<char>> &v, int row, int col);
void output(std::string message);
void getInput(int& row, int &col);
void flipReveal(std::vector<std::vector<char>> &front, std::vector<std::vector<char>> &back, int row, int col);
void update(std::vector<std::vector<char>> &back, int row, int col, char value);
void promptInput(int& row, int& col, std::string message);

#endif //MATCHINGPUZZLE_VECTOR_FUNCTIONS_H
