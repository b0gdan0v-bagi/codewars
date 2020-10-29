#include <iostream>
#include <iostream>
#include <string>
#include <sstream> 
#include <vector>

using namespace std;

struct p
{
    int x, y;
};

int find_posible(p pos, int count, std::vector<std::vector<int>>& field)
{

    int counter = 0;
    if (field[pos.x][pos.y + 1] == 0) {
        field[pos.x][pos.y + 1] = field[pos.x][pos.y] + 1;
        counter++;
    }
    if (field[pos.x + 1][pos.y] == 0) {
        field[pos.x + 1][pos.y] = field[pos.x][pos.y] + 1;
        counter++;
    }
    if (field[pos.x - 1][pos.y] == 0) {
        field[pos.x - 1][pos.y] = field[pos.x][pos.y] + 1;
        counter++;
    }

    if (field[pos.x][pos.y - 1] == 0) {
        field[pos.x][pos.y - 1] = field[pos.x][pos.y] + 1;
        counter++;
    }
    return counter;
}


int path_finder(std::string maze) {

    std::vector<int> dist;
    std::string to;
    std::vector<std::string> lines;
    std::vector<std::vector<int>> field;
    std::stringstream ss(maze);
    while (std::getline(ss, to, '\n')) lines.push_back(to);
    std::string extraWall;
    for (int i = 0; i < lines[0].size(); i++) extraWall += 'W';
    lines.insert(lines.begin(), extraWall);
    lines.push_back(extraWall);
    for (auto& i : lines)
    {
        i.insert(i.begin(), 'W');
        i += 'W';
    }

    for (auto& i : lines)
    {
        std::vector<int> tmp;
        for (auto& j : i)
        {
            if (j == 'W') tmp.push_back(-1);
            else tmp.push_back(0);
        }
        field.push_back(tmp);
    }

    p pp; pp.x = 1; pp.y = 1;
    p pEnd; pEnd.x = field[0].size() - 2; pEnd.y = field.size() - 2;

    if (lines.size() == 3) return 0;

    int ans = 0;
    if (find_posible(pp, 0, field) == 0) return -1;
    int counter = 1;
    while (true)
    {
        ans = 0;
        for (int i = 1; i < field.size() - 1; i++)
        {
            for (int j = 1; j < field[i].size() - 1; j++)
            {
                if (field[i][j] == counter)
                {
                    pp.x = i; pp.y = j;
                    ans += find_posible(pp, counter, field);
                }
            }
        }

        if (field[pEnd.x][pEnd.y] != 0) return field[pEnd.x][pEnd.y];
        if (ans == 0) return -1;
        counter++;
    }

    return -1;
}

int main()
{
    /*
    https://www.codewars.com/kata/57658bfa28ed87ecfa00058a
    */
    std::cout << "Hello World!\n";
}
