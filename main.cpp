#include <iostream>
#include <vector>
#include <ctime>
#include "vector_functions.h"

int main()
{
    srand(time(0));
    std::vector<std::vector<char>> front = createArray(4, 4);
    fill(front);
    std::vector<std::vector<char>> back = createArray(4, 4);
    int row1, row2, col1, col2;
    do
    {
        promptInput(row1, col1, "Enter a row and col:", back, front);
        promptInput(row2, col2, "Enter a second row and col:", back, front);
        if(front[row1][col1] != front[row2][col2])
        {
            update(back, row1, col1, '#');
            update(back, row2, col2, '#');
        }

    }
    while(front != back);
    return 0;
}