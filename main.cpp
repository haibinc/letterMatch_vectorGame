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
    std::cout << "Enter a filename: " << std::endl;
    std::cin >> fileName;
    createFile(fout, fileName);
    std::vector<std::vector<char>> front = createArray(4, 4);
    fill(front);
    print(front, fout, fileName);
    std::vector<std::vector<char>> back = createArray(4, 4);
    int row1, row2, col1, col2;
    do
    {
        promptInput(row1, col1, "Enter a row and col:");
        flipReveal(front, back, row1, col1);
        print(back, fout, fileName);
        promptInput(row2, col2, "Enter a second row and col:");
        flipReveal(front, back, row2, col2);
        print(back, fout, fileName);

        if(back[row1-1][col1-1] != back[row2-1][col2-1])
        {
            update(back, row1, col1, '#');
            update(back, row2, col2, '#');
        }
    }
    while(front != back);

    output("You won, nice one dude");


    return 0;
}