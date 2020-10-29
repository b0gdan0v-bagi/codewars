#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <set>

class SumOfDivided
{
public:
    static std::string sumOfDivided(std::vector<int>& lst)
    {
        std::set<int> set; // set of all primes
        std::vector<int> temp = lst; //temp will be modulus(lst)
        for (auto i = temp.begin(); i != temp.end(); i++)
        {
            if ((*i) < 0) (*i) *= -1;
            std::vector<int> vec = primeFactors(*i);
            std::copy(vec.begin(), vec.end(), std::inserter(set, set.end()));
        }
        std::string res;

        for (auto& i : set)
        {
            int sum = 0;
            for (auto j = lst.begin(); j != lst.end(); j++)
            {
                if ((*j) % i == 0) sum += (*j);
            }
            res += "(" + std::to_string(i) + " " + std::to_string(sum) + ")";
        }

        return res;
    }
    static std::vector<int> primeFactors(int n)
    {
        std::vector<int> primeNumbers;
        while (n % 2 == 0)
        {
            primeNumbers.push_back(2);
            n = n / 2;
        }
        for (int i = 3; i <= sqrt(n); i = i + 2)
        {
            while (n % i == 0)
            {
                primeNumbers.push_back(i);
                n = n / i;
            }
        }
        if (n > 2)
            primeNumbers.push_back(n);
        return primeNumbers;
    }
};

int main()
{
    /*
    https://www.codewars.com/kata/54d496788776e49e6b00052f
    */
    std::cout << "Hello World!\n";
}
