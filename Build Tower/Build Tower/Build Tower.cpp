#include <iostream>
#include <vector>
class Kata
{
public:
    std::vector<std::string> towerBuilder(int nFloors)
    {
        std::vector<std::string> answer;
        std::string word;

        for (int i = 0; i < nFloors; i++)
        {
            word = "";
            for (int j = 0; j < nFloors - i - 1; j++) word += " ";
            for (int j = 0; j < i * 2 + 1; j++) word += "*";
            for (int j = nFloors - i + i * 2; j < nFloors * 2 - 1; j++) word += " ";

            answer.push_back(word);
        }

        return answer;
    }
};

int main()
{
    /*
    https://www.codewars.com/kata/576757b1df89ecf5bd00073b
    */
    std::cout << "Hello World!\n";
}
