#include <iostream>
#include <cstdlib> // abs

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int count; std::cin >> count;
    int maxStrLen = (2 * count) - 1;

    for(int loop = 0; loop < maxStrLen; loop++)
    {
        for (int strIndex = 0; strIndex < maxStrLen; strIndex++)
        {
            int gap = abs(count - loop - 1);
            if (strIndex < gap)
                std::cout << " ";
            else if (maxStrLen - (gap + 1) < strIndex)
                continue;
            else
                std::cout << "*";
        }

        std::cout << "\n";
    }

    return 0;
}