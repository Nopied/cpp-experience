#include <iostream>

int classes[14] = {0};

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int count, roomLimit;
    std::cin >> count >> roomLimit;

    for(int loop = 0; loop < count; loop++)
    {
        int a, b;
        std::cin >> a >> b;

        int realIndex = (b * 2) + a;
        // std::cout << realIndex << " ";
        classes[realIndex]++;
    }

    int roomCount = 0;
    for (int loop = 1; loop < 14; loop++)
    {
        roomCount += classes[loop] / roomLimit;
        if (classes[loop] % roomLimit > 0)
            roomCount++;
    }

    std::cout << roomCount;

    return 0;
}