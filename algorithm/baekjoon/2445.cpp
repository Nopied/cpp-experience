#include <iostream>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int count; std::cin >> count;
    int maxline = (2 * count) - 1,
        maxStrLen = 2 * count;

    for (int loop = 0; loop < maxline; loop++)
    {
        std::string str(maxStrLen, ' ');

        int gap, currentStar;
        if (loop + 1 < count)
            gap = loop + 1;
        else
            gap = maxStrLen - (loop + 1);

        currentStar = 0; 
        for (int strIndex = 0; strIndex < count; strIndex++)
        {
            if (currentStar < gap)
            {
                str[strIndex] = '*';
                currentStar++;
            }
            else
                str[strIndex] = ' ';
        }

        currentStar = 0;
        for (int strIndex = maxStrLen - 1; strIndex >= count; strIndex--)
        {
            if (currentStar < gap)
            {
                str[strIndex] = '*';
                currentStar++;
            }
            else
                str[strIndex] = ' ';
        }

        std::cout << str;
        std::cout << "\n";
    }

    return 0;
}