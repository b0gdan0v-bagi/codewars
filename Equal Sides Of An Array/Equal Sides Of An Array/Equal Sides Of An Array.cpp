#include <vector>
#include <numeric>
using namespace std;

int find_even_index(const vector <int> numbers) {
    int left = 0;
    int right = 0;
    for (auto const& i : numbers) right += i;
    if (left == right) return 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        left = 0;
        for (int j = 0; j < i; j++) left += numbers[j];
        right = 0;
        for (int j = i + 1; j < numbers.size(); j++) right += numbers[j];
        if (left == right) return i;
    }

    return -1;
}

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}


