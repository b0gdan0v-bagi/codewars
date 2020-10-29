#include <iostream>
#include <map>
#include <vector>

class Mix
{
public:
    static std::map<char, std::string> sorting(std::string s)
    {
        std::map<char, std::string> res;
        for (auto i = 0; i < s.size(); i++)
            if ((s[i] < 'a') || (s[i] > 'z'))
            {
                s.erase(i, 1);
                i--;
            }
            else res[s[i]] += s[i];
        return res;
    }

    static std::string mix(const std::string& s1, const std::string& s2)
    {
        std::map<int, std::vector<std::string>> ans;
        std::string res;
        std::string temp;
        std::map<char, std::string> mapS1 = sorting(s1), mapS2 = sorting(s2);
        char c = 'a';
        while (c <= 'z')
        {
            if ((mapS1[c].size() > 1) || (mapS2[c].size() > 1))
            {
                if (mapS1[c].size() == mapS2[c].size())
                    ans[mapS1[c].size()].push_back("=:" + mapS1[c]);

                if ((mapS1[c].size() > mapS2[c].size()) && (mapS1[c].size() > 1))
                    ans[mapS1[c].size()].push_back("1:" + mapS1[c]);

                if ((mapS1[c].size() < mapS2[c].size()) && (mapS2[c].size() > 1))
                    ans[mapS2[c].size()].push_back("2:" + mapS2[c]);
            }
            c++;
        }
        // buble sorting for ascending lexicographic order :D
        for (auto it = ans.begin(); it != ans.end(); it++)
            for (int i = 0; i < (*it).second.size() - 1; i++)
                for (int j = i + 1; j < (*it).second.size(); j++)
                    if ((*it).second[i] > (*it).second[j])
                    {
                        temp = (*it).second[i];
                        (*it).second[i] = (*it).second[j];
                        (*it).second[j] = temp;
                    }
        for (auto it = ans.rbegin(); it != ans.rend(); it++)
            for (auto i = (*it).second.begin(); i != (*it).second.end(); i++) res += (*i) + "/";
        if (res.size() > 0) res.pop_back();
        return res;
    }
};

int main()
{
    /*
    https://www.codewars.com/kata/5629db57620258aa9d000014
    */
    std::cout << "Hello World!\n";
}
