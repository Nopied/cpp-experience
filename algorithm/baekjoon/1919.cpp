#include <iostream>
#include <cmath>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int letter[26] = {0}, guess[26] = {0};

    std::string str;        std::cin >> str;
    int len = str.length();

    for (int search = 0; search < len; search++)
    {
        letter[str[search] - 97]++;
    }

    std::cin >> str;
    len = str.length();
    for (int search = 0; search < len; search++)
    {
        guess[str[search] - 97]++;
    }

    int answer = 0;
    for (int search = 0; search < 26; search++)
    {
        answer += abs(letter[search] - guess[search]);
    }

    std::cout << answer;
    return 0;
}