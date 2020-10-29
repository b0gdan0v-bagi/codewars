#include <iostream>
#include <string>
#include <vector>
#include <set>

std::vector<char> getPossible(char c)
{
    switch (c)
    {
    case '1':  return { '1','2','4' };
    case '2': return { '1','2','3','5' };
    case '3': return { '2','3','6' };
    case '4': return { '1', '4','5','7' };
    case '5': return { '2','4','5','6','8' };
    case '6': return { '3','5','6','9' };
    case '7': return { '4','7','8' };
    case '8': return { '5','7','8','9','0' };
    case '9': return { '6','8','9' };
    case '0': return { '0','8' };
    default:
        break;
    }
}

std::vector<std::string> get_pins(std::string observed) {
    std::set<std::string> res;
    std::vector<std::vector<char>> possible;
    std::string pass;

    for (auto i = observed.begin(); i != observed.end(); i++) possible.push_back(getPossible(*i));


    std::vector<std::vector<char>::iterator> it;
    std::vector<std::vector<char>::iterator> it_start;
    std::vector<std::vector<char>::iterator> it_end;
    for (auto i = possible.begin(); i != possible.end(); i++)
    {
        std::vector<char>::iterator buf = (*i).begin();
        it.push_back((*i).begin());
        it_start.push_back((*i).begin());
        it_end.push_back((*i).end() - 1);
    }
    int size = it.size() - 1;
    while (true)
    {
        pass = "";
        for (auto i = it.begin(); i != it.end(); i++)
        {
            pass += (**i);
        }
        res.insert(pass);
        it[size]++;
        //std::cout << pass << "\n";
        for (int i = size; i >= 1; i--)
        {
            if (it[i] == it_end[i] + 1)
            {
                it[i] = it_start[i];
                it[i - 1]++;
            }

        }
        if (it[0] == it_end[0] + 1) { break; }
    }


    std::vector<std::string> output(res.begin(), res.end());
    return output;
}

int main()
{
    /*
    https://www.codewars.com/kata/5263c6999e0f40dee200059d
    */
    std::cout << "Hello World!\n";
}
