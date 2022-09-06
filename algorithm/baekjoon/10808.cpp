#include <iostream>

int answer[26] = {0};

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::string line(100, ' '); std::cin >> line;

    for(int loop = 0; loop < 100; loop++)
    {
        answer[int(line[loop]) - 97]++;
    }

    for(int loop = 0; loop < 26; loop++)
    {
        std::cout << answer[loop] << " ";   
    }

    return 0;
}