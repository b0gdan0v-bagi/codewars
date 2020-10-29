#include <iostream>

typedef unsigned long long ull;
class SumFct
{
public:
    static ull perimeter(int n);
};

ull SumFct::perimeter(int n)
{
    ull a = 1;
    ull b = 1;
    ull sum = a + b;
    while (n - 2 >= 0)
    {

        std::swap(a, b);
        b = a + b;
        sum += b;
        n--;
    }
    return sum * 4;
}

int main()
{
    /*
    https://www.codewars.com/kata/559a28007caad2ac4e000083
    */
    std::cout << "Hello World!\n";
}
