// CPP program to generate all unique 
// partitions of an integer 
#include <iostream> 
#include <stdlib.h>  
#include <sstream>   
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <algorithm>
#include <map>
#include <list>

int Modulo(int a, const std::string& str2)
{
    int mod = 0;
    for (int i = 0; i < str2.size(); i++)
        mod = (mod * 10 + str2[i] - '0') % a;

    return mod; // return modulo 
}

int last_digit_pair(const std::string& str1, const std::string& str2) {
    //std::cout << str1 << "\n" << str2 << "\n";
    int len_a = str1.size(), len_b = str2.size();
    if (len_a == 1 && len_b == 1 && str2[0] == '0' && str1[0] == '0')
        return 1;

    if (len_b == 1 && str2[0] == '0')
        return 1;

    if (len_a == 1 && str1[0] == '0')
        return 0;

    int exp = (Modulo(4, str2) == 0) ? 4 : Modulo(4, str2);
    int res = pow(str1[len_a - 1] - '0', exp);
    return res % 10;
}

int last_digit(std::list<int> array) {
    std::vector<int> v{ std::begin(array), std::end(array) };
    for (auto& i : v) std::cout << " " << i;
    std::cout << "\n";
    switch (v.size())
    {
    case 0: return 1;
    case 1: { auto it = v.begin();
        std::string s = std::to_string(*it);
        return s[s.size() - 1] - '0';
    }
    case 2: { auto it = v.begin();
        return last_digit_pair(std::to_string(*it), std::to_string((*it++)));
    }
    default: {
        
        auto it = array.rbegin();
        auto it2 = it;
        it2++;
        int r = last_digit_pair(std::to_string(*it2), std::to_string(*it));
        array.pop_back();
        array.pop_back();
        array.push_back(r);
        for (auto& i : array) std::cout << " " << i;
        std::cout << "array\n";
        return last_digit(array);
        /*int r = 1;
        std::cout << v[v.size() - 1];
        for (int i = v.size()-1; i>=0; i--)
        {
            auto j = i-1;
            if (j == -1) return r;
            //it2++;
            //std::cout << j << " " << i << "\n";
            //std::cout << v[j] << " " << v[i] << "\n";
            for (auto& e : v) std::cout << " " << e;
            std::cout << "\n";
            //if (it2 == array.rend()) return r;
            //std::cout << *it2;
            r = last_digit_pair(std::to_string(v[j]), std::to_string(v[i]));
            std::cout << r << "\n";
            v[i] = r;
            //array.pop_back();
            //array.pop_back();
            //array.push_back(r);
        }*/
        break;
    }
    }
    return -1;
}

// Driver program to test above functions 
int main()
{
    
    std::cout << last_digit_pair("6","21") << "\n";
    //std::cout << last_digit({1533}) << "\n";
    std::cout << last_digit({ 7,6,21 }) << "\n";
    //std::cout << last_digit({ 1,2 }) << "\n";

    std::string s1 = "my&friend&Paul has heavy hats! &";
    std::string s2 = "my friend John has many many friends &";
    //std::cout << mix(s1, s2);
    return 0;
}