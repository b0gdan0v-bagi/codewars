#include <iostream>
#include <vector>

bool validSolution(unsigned int board[9][9]) {
    int small[9];
    int a = 0;
    for (int i = 0; i < 9; i++)
    {
        std::vector<int> v{ 1,2,3,4,5,6,7,8,9 };
        std::vector<int> v2{ 1,2,3,4,5,6,7,8,9 };
        std::vector<int> v3{ 1,2,3,4,5,6,7,8,9 };
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {

                small[k * 3 + j] = board[(i / 3) * 3 + j][a * 3 + k];
            }
        }
        a++;
        if (a > 2) a = 0;
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0) return false;
            v.erase(std::remove(v.begin(), v.end(), board[i][j]), v.end());
            v2.erase(std::remove(v2.begin(), v2.end(), board[j][i]), v2.end());
            v3.erase(std::remove(v3.begin(), v3.end(), small[j]), v3.end());

        }

        if ((v.size() != 0) || (v2.size() != 0) || (v3.size() != 0)) return false;

    }

    return true;
}

int main()
{
    /*
    https://www.codewars.com/kata/529bf0e9bdf7657179000008
    */
    std::cout << "Hello World!\n";
}
