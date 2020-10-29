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

std::vector<p> find_posible(p pos, std::vector<std::string> lines)
{
    std::vector<p> res;
    p pp;
    if (lines[pos.x - 1][pos.y] != 'W') {
        pp.x = pos.x - 1; pp.y = pos.y;  res.push_back(pp);
    }
    if (lines[pos.x + 1][pos.y] != 'W') {
        pp.x = pos.x + 1; pp.y = pos.y;  res.push_back(pp);
    }
    if (lines[pos.x][pos.y - 1] != 'W') {
        pp.x = pos.x; pp.y = pos.y - 1;  res.push_back(pp);
    }
    if (lines[pos.x][pos.y + 1] != 'W') {
        pp.x = pos.x; pp.y = pos.y + 1;  res.push_back(pp);
    }
    return res;
}

bool move(p& pos, std::vector<std::string>& lines)
{
    std::vector<p> ask = find_posible(pos, lines);
    for (auto& i : ask)
        if ((i.x == lines[0].size() - 2) && (i.y == lines.size() - 2)) return true;

    if (ask.size() == 0) return false;
    else
    {
        lines[pos.x][pos.y] = 'W';
        for (auto& i : ask)
        {
            if (move(i, lines)) return true;
        }
    }
    return false;
}

bool path_finder(std::string maze) {


    std::string to;
    std::vector<std::string> lines;
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
    p pp; pp.x = 1; pp.y = 1;
    if (move(pp, lines)) return true;
    return false;
}

int main()
{
    /*
    https://www.codewars.com/kata/5765870e190b1472ec0022a2
    */
    std::cout << "Hello World!\n";
}
