#include <iostream>
#include <vector>
typedef unsigned long long ull;
class ProdFib
{
public:
    static std::vector<ull> productFib(ull prod);
};

std::vector<ull> ProdFib::productFib(ull prod)
{
    std::vector<ull> p;
    unsigned long long  a = 0;
    unsigned long long  b = 1;
    unsigned long long  temp;
    while (prod > a * b)
    {
        temp = b;
        b = b + a;
        a = temp;
        if (prod == a * b)
        {
            p.push_back(a);
            p.push_back(b);
            p.push_back(1);
            return p;
        }
    }
    p.push_back(a);
    p.push_back(b);
    p.push_back(0);
    return p;
}

int main()
{
    /*
    https://www.codewars.com/kata/5541f58a944b85ce6d00006a
    */
    std::cout << "Hello World!\n";
}
