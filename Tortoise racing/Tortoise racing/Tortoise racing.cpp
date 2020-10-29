#include <iostream>
#include <vector>

class Tortoise
{
public:
    static std::vector<int> race(int v1, int v2, int g);
};

std::vector<int> Tortoise::race(int v1, int v2, int g)
{
    if (v1 >= v2) return { -1,-1,-1 };
    float sec = (3600 * g) / (v2 - v1);
    int h = sec / 3600;
    sec -= h * 3600;
    int m = sec / 60;
    sec -= m * 60;
    int s = sec;
    return { h,m,s };
}

int main()
{
    /*
    https://www.codewars.com/kata/55e2adece53b4cdcb900006c
    */
    std::cout << "Hello World!\n";
}

