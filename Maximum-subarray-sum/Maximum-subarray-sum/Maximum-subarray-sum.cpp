
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int maxSequence(const vector<int>& arr) {
    if (arr.size() == 0) return 0;
    bool b = false;
    for (auto& i : arr)
        if (i > 0) b = true;
    for (auto& i : arr) cout << " " << i;
    cout << "\n";
    if (!b) return 0;
    vector<int> v;
    int num;
    for (int i = 0; i < arr.size(); i++)
    {

        for (int j = arr.size(); j != i; j--)
        {
            num = 0;
            for (int k = i; k != j; k++) num += arr[k];
            v.push_back(num);
        }
    }

    return *std::max_element(v.begin(), v.end());
}

int main()
{
    //std::cout << maxSequence({ -2, 1, -3, 4, -1, 2, 1, -5, 4 });
    assert(6 == maxSequence({ -2, 1, -3, 4, -1, 2, 1, -5, 4 }));
    
}
