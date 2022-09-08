#include <iostream>

int iCount[201] = {0};

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int count; std::cin >> count;

    for(int loop = 0; loop < count; loop++)
    {
        int current; std::cin >> current;

        iCount[current + 100]++;
    }

    int guess; std::cin >> guess;
    std::cout << iCount[guess + 100];

    return 0;
}