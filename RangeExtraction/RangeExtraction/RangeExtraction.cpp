#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string range_extraction(std::vector<int> args) {
    std::string res = "";
    std::vector<int> v = args;
    std::sort(v.begin(), v.end());
    v.push_back(v[v.size() - 1] + 10);
    v.push_back(v[v.size() - 1] + 10);
    for (int i = 0; i < v.size() - 2;)
    {
        if (v[i + 2] == v[i] + 2)
        {
            int start = i;
            res += std::to_string(v[start]) + "-";
            int end = i + 2;
            while (v[end + 1] == v[end] + 1) end++;
            res += std::to_string(v[end]) + ",";
            i = end + 1;
        }
        else
        {
            res += std::to_string(v[i]) + ",";
            i++;
        }
    }
    res.pop_back();
    return res;
}

int main()
{
    /*
    https://www.codewars.com/kata/51ba717bb08c1cd60f00002f
    */
    std::cout << "Hello World!\n";
}
