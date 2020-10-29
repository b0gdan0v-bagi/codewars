#include <iostream>
#include <string>

std::string uint32_to_ip(uint32_t ip)
{
    std::string answer;
    answer.insert(0, "." + std::to_string(ip % 256));
    ip /= 256;
    answer.insert(0, "." + std::to_string(ip % 256));
    ip /= 256;
    answer.insert(0, "." + std::to_string(ip % 256));
    ip /= 256;
    answer.insert(0, std::to_string(ip % 256));
    ip /= 256;
    return answer;
}

int main()
{
    /*
    https://www.codewars.com/kata/52e88b39ffb6ac53a400022e
    */
    std::cout << "Hello World!\n";
}
