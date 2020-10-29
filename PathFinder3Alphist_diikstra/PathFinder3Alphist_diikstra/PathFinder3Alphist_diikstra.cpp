#include <iostream>
#include <stdlib.h>  
#include <algorithm>
#include <vector>
#include <sstream>

int path_finder(std::string maze) {
    std::string to;
    std::vector<std::vector<int>> field;
    std::vector<std::vector<int>> map;
    std::stringstream ss(maze);
    while (std::getline(ss, to, '\n'))
    {
        std::vector<int> temp_map;
        std::vector<int> temp_field;
        for (auto& i : to)
        {
            int t = i - '0';
            temp_map.push_back(t);
            temp_field.push_back(-1);
        }
        map.push_back(temp_map);
        field.push_back(temp_field);
    }


    std::vector<int> wall;
    for (int i = 0; i < map[0].size(); i++) wall.push_back(-2);
    map.insert(map.begin(), wall);
    map.push_back(wall);
    field.insert(field.begin(), wall);
    field.push_back(wall);
    for (auto& i : map)
    {
        i.insert(i.begin(), -2);
        i.push_back(-2);
    }
    for (auto& i : field)
    {
        i.insert(i.begin(), -2);
        i.push_back(-2);
    }

    if (field.size() == 3) return 0;

    field[1][1] = 0;

    // k is hard-coding parametr of number of iterations
  // it is a compromise between guarantee of results and performance

    for (int k = 0; k < field.size(); k++)
        for (int x = 1; x < field.size() - 1; x++)
            for (int y = 1; y < field[x].size() - 1; y++)
            {
                if (field[x][y + 1] != -2)
                {
                    if (field[x][y + 1] == -1) {
                        field[x][y + 1] = field[x][y] + abs(map[x][y] - map[x][y + 1]);
                    }
                    else if (field[x][y + 1] - field[x][y] > abs(map[x][y] - map[x][y + 1]))
                    {
                        field[x][y + 1] = field[x][y] + abs(map[x][y] - map[x][y + 1]);
                    }
                }
                if (field[x + 1][y] != -2)
                {
                    if (field[x + 1][y] == -1) {
                        field[x + 1][y] = field[x][y] + abs(map[x][y] - map[x + 1][y]);
                    }
                    else if (field[x + 1][y] - field[x][y] > abs(map[x][y] - map[x + 1][y]))
                    {
                        field[x + 1][y] = field[x][y] + abs(map[x][y] - map[x + 1][y]);
                    }
                }
                if (field[x - 1][y] != -2)
                {
                    if (field[x - 1][y] == -1)
                    {
                        field[x - 1][y] = field[x][y] + abs(map[x][y] - map[x - 1][y]);
                    }
                    else if (field[x - 1][y] - field[x][y] > abs(map[x][y] - map[x - 1][y]))
                    {
                        field[x - 1][y] = field[x][y] + abs(map[x][y] - map[x - 1][y]);
                    }
                }

                if (field[x][y - 1] != -2)
                {
                    if (field[x][y - 1] == -1)
                    {
                        field[x][y - 1] = field[x][y] + abs(map[x][y] - map[x][y - 1]);
                    }
                    else if (field[x][y - 1] - field[x][y] > abs(map[x][y] - map[x][y - 1]))
                    {
                        field[x][y - 1] = field[x][y] + abs(map[x][y] - map[x][y - 1]);
                    }
                }
            }

    return field[field[0].size() - 2][field.size() - 2];
}


int main()
{
    /*
    https://www.codewars.com/kata/576986639772456f6f00030c
    */
    std::cout << "Hello World!\n";
}
