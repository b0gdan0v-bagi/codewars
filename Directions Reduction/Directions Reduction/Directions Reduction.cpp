#include <iostream>
#include <vector>

class DirReduction
{
public:
    static std::vector<std::string> dirReduc(std::vector<std::string>& arr);
};

std::vector<std::string> DirReduction::dirReduc(std::vector<std::string>& arr)
{
    bool isEnd = true;
    if (arr.size() < 2) return arr;
    while (isEnd)
    {
        isEnd = false;
        for (int i = 1; i < arr.size(); i++)
        {
            if ((arr[i] == "NORTH") && (arr[i - 1] == "SOUTH")) { arr[i] = arr[i - 1] = "="; isEnd = true; }
            if ((arr[i] == "SOUTH") && (arr[i - 1] == "NORTH")) { arr[i] = arr[i - 1] = "="; isEnd = true; }
            if ((arr[i] == "WEST") && (arr[i - 1] == "EAST")) { arr[i] = arr[i - 1] = "="; isEnd = true; }
            if ((arr[i] == "EAST") && (arr[i - 1] == "WEST")) { arr[i] = arr[i - 1] = "="; isEnd = true; }
        }

        arr.erase(std::remove(arr.begin(), arr.end(), "="), arr.end());
    }
    return arr;
}

int main()
{
    /*
    https://www.codewars.com/kata/550f22f4d758534c1100025a
    */
    std::cout << "Hello World!\n";
}
