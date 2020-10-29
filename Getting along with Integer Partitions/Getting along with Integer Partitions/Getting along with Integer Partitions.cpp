#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <string>

using namespace std;

class IntPart
{
public:
    static std::string part(long long n)
    {
        vector<int> res = findAllUnique(n);
        set<int> s(res.begin(), res.end());
        auto it = s.begin();
        auto it2 = s.rbegin();
        int si = *it2 - *it;
        float median = findMedian(s);
        float average = accumulate(s.begin(), s.end(), 0.0) / s.size();
        return "Range: " + to_string(si) + " Average: " + to_string_p(average, 2) +
            " Median: " + to_string_p(median, 2);
    }

    static  float findMedian(set<int> s)
    {
        std::set<int>::iterator it = s.begin();
        std::advance(it, s.size() / 2);
        std::set<int>::iterator it2 = s.begin();
        int n = s.size();
        if (n % 2 != 0)
        {


            return *it;
        }

        std::advance(it2, (s.size() - 1) / 2);
        return (double)(*it + *it2) / 2.0;
    }

    template <typename T>
    static std::string to_string_p(const T a_value, const int n = 6)
    {
        std::ostringstream out;
        out.precision(n);
        out << std::fixed << a_value;
        return out.str();
    }

    static  double prod(vector<int> p)
    {
        p.erase(std::remove(p.begin(), p.end(), 0), p.end());
        double multi = 1;
        for (const auto& e : p) multi *= e;
        return multi;
    }

    static vector<int> findAllUnique(int n)
    {
        vector<int> res;
        vector<int> p;
        p.resize(n);
        int k = 0;
        p[k] = n;
        while (true)
        {
            res.push_back(prod(p));
            int rem_val = 0;
            while (k >= 0 && p[k] == 1)
            {
                rem_val += p[k];
                k--;
            }
            if (k < 0)  return res;
            p[k]--;
            rem_val++;
            while (rem_val > p[k])
            {
                p[k + 1] = p[k];
                rem_val = rem_val - p[k];
                k++;
            }
            p[k + 1] = rem_val;
            k++;
        }

    }
};

int main()
{
    /*
    https://www.codewars.com/kata/55cf3b567fc0e02b0b00000b
    */
    std::cout << "Hello World!\n";
}


