#include <iostream>
#include <algorithm>
#include <vector>
#include <istream>
#include <sstream>

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

using namespace std;

std::string highAndLow(const std::string& numbers) {
    std::vector<int> v;
    std::stringstream iss(numbers);
    int number;
    while (iss >> number)
        v.push_back(number);
    for (auto const& i : v) std::cout << " " << i;
    
    return to_string(*std::max_element(v.begin(), v.end())) + " " + to_string(*std::min_element(v.begin(), v.end()));
     
}

int main()
{
    highAndLow("8 3 -5 42 -1 0 0 -9 4 7 4 -4");
}

