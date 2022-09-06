#include <iostream>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::string roomName;

    std::cin >> roomName;
    int nameLen = roomName.length();

    int numbers[10] = {0};
    for(int loop = 0; loop < nameLen; loop++)
    {
        numbers[int(roomName[loop]) - 48]++;
    }

    int innerTotal = numbers[6] + numbers[9];
    numbers[6] = innerTotal / 2;
    numbers[9] = 0;

    if (innerTotal % 2 > 0)
    {
        numbers[6]++;
    }

    int answer = 0;
    for (int loop = 0; loop < 9; loop++)
    {
        if (numbers[loop] > answer)
        {
            answer = numbers[loop];
        }
    }

    std::cout << answer;
    return 0;
}