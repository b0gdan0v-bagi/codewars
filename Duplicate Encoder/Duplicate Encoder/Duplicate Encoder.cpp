#include <iostream>
#include <string>
#include <algorithm>

std::string duplicate_encoder(const std::string& word) {
    std::string answer = word;
    std::string data = word;
    bool once = true;
    std::transform(data.begin(), data.end(), data.begin(),
        [](unsigned char c) { return std::tolower(c); });

    for (int i = 0; i < data.length(); i++)
    {
        for (int j = 0; j < data.length(); j++)
        {
            if ((data[i] == data[j]) && (i != j)) once = false;
        }
        if (once) answer.replace(i, 1, "(");
        else answer.replace(i, 1, ")");
        once = true;
    }
    return answer;
}

int main()
{
    /*
    https://www.codewars.com/kata/54b42f9314d9229fd6000d9c
    */
    std::cout << "Hello World!\n";
}

