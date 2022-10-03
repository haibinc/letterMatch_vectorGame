#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include "vector_functions.h"

int main()
{
    srand(time(0));
    std::ofstream fout;
    std::string fileName;
    std::vector<std::vector<char>> front;
    std::vector<std::vector<char>> back;
    menu(fout, fileName, front, back);

    return 0;
}