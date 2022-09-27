#include <iostream>
#include <string>
#include <vector>
bool check(unsigned value)
{
    std::string s = std::to_string(value);
    unsigned temp;
    for (unsigned i = 0; i < s.length(); ++i)
    {
        if (s[i] == '0')
            return false;
        if (value % (s[i] - '0') != 0)
            return false;
    }
    return true;
}
int main() {
    unsigned N;
    std::vector<unsigned> result = {};
    std::cout << "Введите N:\t";
    std::cin >> N;
    for (unsigned i = 1; i <= N; ++i)
    {
        if (check(i))
            result.push_back(i);
    }
    for (unsigned i : result)
    {
        std::cout << i << "\t";
    }
    return 0;
}
