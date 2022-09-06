#include <iostream>
#include <cstdlib>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int count;
    std::cin >> count;
    int maxline = 2 * count - 1;

    for (int loop = 0; loop < maxline; loop++)
    {
        int mid = count - 1, sideGap = 0;
        if (loop <= mid)
            sideGap = loop;
        else
            sideGap = abs(loop - (maxline - 1));

        for (int strIndex = 0; strIndex < maxline; strIndex++)
        {     
            if (strIndex < sideGap)
            {
                std::cout << " ";
            }
            else if(mid < strIndex && abs(strIndex - (maxline - 1)) < sideGap)
                continue;
            else
                std::cout << "*";
        }

        std::cout << "\n";
    }

    return 0;
}