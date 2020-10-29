#include <iostream>
#include <vector>

using namespace std;

bool validate_battlefield(vector< vector<int> > field) {
    vector<int> border(12, 2);
    for (auto i = field.begin(); i!=field.end();i++)
    {
        (*i).insert((*i).begin(), 2);
        (*i).push_back(2);
    }
    field.insert(field.begin(), border);
    field.push_back(border);
    for (auto const& i : field)
    {
        //for (auto const& j : i) std::cout << j;
        //cout << endl;
    }
    int b = 1, c = 2, d = 3, s = 4;
    int size = 0;
    for (int y = 1; y < field.size() - 1; y++)
    {
        for (int x = 1; x < field[0].size() - 1; x++)
        {
            if (field[y][x] == 1)
            {
                size = 1;
                field[y][x] = 3;
                if ((field[y+1][x-1] == 1) || (field[y + 1][x + 1] == 1)) return false;
                if (field[y][x + 1] == 1)
                {
                    if (field[y + 1][x] == 1) return false;
                    while (field[y][x + size] == 1)
                    {
                        field[y][x + size] = 3;
                        size++;
                        if (size > 5) return false;
                    }
                }
                if (field[y + 1][x] == 1)
                {
                    while (field[y + size][x] == 1)
                    {
                        field[y + size][x] = 3;
                        size++;
                        if (size > 5) return false;
                    }
                }
            }
            switch (size)
            {
            case 1: {s--; break; }
            case 2: {d--; break; }
            case 3: {c--; break; }
            case 4: {b--; break; }
            }
            size = 0;
            //std::cout << s << " " << d << " " << c << " " << b << "\n";
            if ((s == -1) || (d == -1) || (c == -1) || (b == -1)) return false;
            //cout << endl;
            for (auto const& i : field)
            {
                //for (auto const& j : i) std::cout << j;
                //cout << endl;
            }
        }
    }
    if ((s == 0) && (d == 0) && (c == 0) && (b == 0)) return true;
    return false;
}

int main()
{
    std::cout << validate_battlefield(vector<vector<int>> {
            vector<int> {1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
            vector<int> {1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
            vector<int> {1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
            vector<int> {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
            vector<int> {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
            vector<int> {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
            vector<int> {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
            vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    });
}
