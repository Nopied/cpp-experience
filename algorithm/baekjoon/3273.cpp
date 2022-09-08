#include <iostream>

int su[100001] = {0};
bool exist[2000001] = {false};

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    int count; std::cin >> count;

    for(int loop = 0; loop < count; loop++)
        std::cin >> su[loop];

    int guess; std::cin >> guess;
    int answer = 0;

    for (int loop = 0; loop < count; loop++)
    {
        if (guess - su[loop] > 0 && exist[guess - su[loop]])
            answer++;

        exist[su[loop]] = true;
    }

    std::cout << answer;

    return 0;
}