#include <iostream>
#include <algorithm>

size_t duplicateCount(const char* in)
{
    size_t res = 0;
    size_t n = 0;
    std::string str = in;
    for (auto& i : str) i = tolower(i);
    char c = 'a';
    while (c <= 'z')
    {
        n = std::count(str.begin(), str.end(), c);
        if (n > 1) res++;
        c++;
    }
    c = '0';
    while (c <= '9')
    {
        n = std::count(str.begin(), str.end(), c);
        if (n > 1) res++;
        c++;
    }
    return res;
}

int main()
{
    std::cout << tolower('z');
}

