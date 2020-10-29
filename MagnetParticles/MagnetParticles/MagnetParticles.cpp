#include <iostream>
#include <cmath>   

class Magnets
{
public:
    static double v(int k, int n)
    {
        double res;
        res = pow((n + 1), 2 * k);
        res = 1 / (k * res);
        return res;
    }

    static double doubles(int maxk, int maxn)
    {
        double res = 0;
        for (int k = 1; k <= maxk; k++)
            for (int n = 1; n <= maxn; n++)
            {
                res += v(k, n);
            }
        return res;
    }
};

int main()
{
    /*
    https://www.codewars.com/kata/56c04261c3fcf33f2d000534
    */
    std::cout << "Hello World!\n";
}
