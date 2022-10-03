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

void print(std::vector<std::vector<char>> v, std::ofstream& fout)
{
    for (int i = 0; i < v.size(); ++i)
    {
        fout << i+1 << ": ";
        std::cout << i+1 << ": ";
        for (int j = 0; j < v[i].size(); ++j)
        {
            fout.width(3);
            std::cout.width(3);
            fout << v[i][j];
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

void saveFile(std::vector<std::vector<char>>& front, std::vector<std::vector<char>>& back, std::string fileName)
{
    std::ofstream fout;
    std::cout << "Name a savefile: " << std::endl;
    std::cin >> fileName;
    fout.open(fileName);

    for (int i = 0; i < back.size(); ++i)
    {
        for (int j = 0; j < back[i].size(); ++j)
        {
            fout.width(3);
            fout << front[i][j];
        }
        fout << std::endl;
    }
    fout << 'd' << std::endl;
    for (int i = 0; i < back.size(); ++i)
    {
        for (int j = 0; j < back[i].size(); ++j)
        {
            fout.width(3);
            fout << back[i][j];
        }
        fout << std::endl;
    }
    fout.close();
}

void readFile(std::vector<std::vector<char>>& front, std::vector<std::vector<char>>& back, std::string fileName)
{
    std::ifstream fin;
    char c;
    int row = 0, col = 0, idx = 0;
    std::string test;
    fin.open(fileName);
    if(fin.fail())
    {
        std::cout << "No such file" << std::endl;
        exit(1);
    }
    std::vector<char> random;
    while(fin >> c)
    {
        col++;
        random.push_back(c);
        if(fin.get() == '\n')
        {
            row++;
        }
        if(fin.get() == 'd')
        {
            break;
        }
    }
    col = col / row;
    front = std::vector<std::vector<char>> (row, std::vector<char>(col));
    back = std::vector<std::vector<char>> (row, std::vector<char>(col));
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            front[i][j] = random[idx++];
        }
    }
    while(fin >> c)
    {
        random.push_back(c);
    }
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            back[i][j] = random[idx++];
        }
    }
    fin.close();
}

void loadFiles(std::vector<std::vector<char>>& front, std::vector<std::vector<char>>& back, std::ofstream& fout, std::string& fileName)
{
    fout.open(fileName);
    print(front, fout);
    print(back, fout);
}

void saveAnswerKey()
{

}

void menu(std::ofstream& fout, std::string& fileName, std::vector<std::vector<char>>& front, std::vector<std::vector<char>>& back)
{
    int choice;
    std::cout << "Would you like to:\n"
              << "(1) Create a new game\n"
              << "(2) Load a saved game\n"
              << "(3) See the solve to your game\n";
    std::cin >> choice;
    switch(choice)
    {
        case 1: {
            srand(time(0));
            std::ofstream fout;
            std::string fileName;
            char saveChoice;
            std::cout << "Enter a filename: " << std::endl;
            std::cin >> fileName;
            createFile(fout, fileName);
            front = createArray(4, 4);
            back = createArray(4, 4);
            fill(front);
            print(front, fout);
            int row1, row2, col1, col2;
            do {
                promptInput(row1, col1, "Enter a row and col:");
                flipReveal(front, back, row1, col1);
                print(back, fout);
                promptInput(row2, col2, "Enter a second row and col:");
                flipReveal(front, back, row2, col2);
                print(back, fout);

                if (back[row1 - 1][col1 - 1] != back[row2 - 1][col2 - 1]) {
                    update(back, row1, col1, '#');
                    update(back, row2, col2, '#');
                } else {
                    output("Would you like to save? (y/n) ");
                    std::cin >> saveChoice;
                    if (saveChoice == 'y') {
                        saveFile(front, back, fileName);
                    }
                }
            } while (front != back);
            output("You won, nice one dude");
            break;
        }
        case 2:
        {
            int row1, row2, col1, col2;
            char saveChoice;
            output("What is your save file's name: ");
            std::cin >> fileName;
            readFile(front, back, fileName);
            output("What is your game file's name: ");
            std::cin >> fileName;
            loadFiles(front, back, fout, fileName);
            do {
                promptInput(row1, col1, "Enter a row and col:");
                flipReveal(front, back, row1, col1);
                print(back, fout);
                promptInput(row2, col2, "Enter a second row and col:");
                flipReveal(front, back, row2, col2);
                print(back, fout);

                if (back[row1 - 1][col1 - 1] != back[row2 - 1][col2 - 1]) {
                    update(back, row1, col1, '#');
                    update(back, row2, col2, '#');
                } else {
                    output("Would you like to save? (y/n) ");
                    std::cin >> saveChoice;
                    if (saveChoice == 'y') {
                        saveFile(front, back, fileName);
                    }
                }
            } while (front != back);
            output("You won, nice one dude");
            break;
        }
        case 3:
        {
            output("What is your save file's name.");
            std::cin >> fileName;
            readFile(front, back, fileName);
            print(front, fout);
            break;
        }

    }
}



