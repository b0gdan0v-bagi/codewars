#include <iostream>
#include <vector>
using ull = unsigned long long;

ull table[10000][10000] = { 0 };

ull partition(int sum, int largestNumber) {
    if (largestNumber == 0)
        return 0;
    if (sum == 0)
        return 1;
    if (sum < 0)
        return 0;

    if (table[sum][largestNumber] != 0)
        return table[sum][largestNumber];

    table[sum][largestNumber] = partition(sum, largestNumber - 1)
        + partition(sum - largestNumber, largestNumber);
    return table[sum][largestNumber];

}


ull exp_sum(ull n)
{
    if (n == 0) return 1;
    return partition(n, n);
}

int main()
{
    /*
    https://www.codewars.com/kata/52ec24228a515e620b0005ef
    */
    std::cout << "Hello World!\n";
}
