#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int count; cin >> count;
    for(int loop = 0; loop < count; loop++)
    {
        deque<int> que;
        string commands; cin >> commands;

        int suCount; cin >> suCount;
        string numbers; cin >> numbers;

        bool isNumber = false;
        int currentNumber = 0;

        suCount = numbers.length();
        for (int search = 0; search < suCount; search++)
        {
            bool isCurrentNumber = 
                48 <= (int)numbers[search] && (int)numbers[search] <= 57;

            // cout << "numbers: " << (int)numbers[search] << "\n";

            if (isNumber && !isCurrentNumber)
            {
                que.push_back(currentNumber);

                // cout << "Pushed " << currentNumber << "\n";
                currentNumber = 0;
            }
            else if (isCurrentNumber)
            {
                currentNumber *= 10;
                currentNumber += numbers[search] - 48;
                // cout << "currentNumber: " << currentNumber << "\n";
            }

            isNumber = isCurrentNumber;
            // cout << isNumber << " " << isCurrentNumber;
        }

        int commandLen = commands.length();
        bool isReversed = false, isError = false;
        for (int search = 0; search < commandLen; search++)
        {
            switch (commands[search])
            {
                case 'R':
                {
                    isReversed = !isReversed;
                    break;
                }
                case 'D':
                {
                    if (que.empty())
                    {
                        isError = true;
                        break;
                    }

                    if (!isReversed)
                        que.pop_front();
                    else
                        que.pop_back();
                }
            }

            if (isError)
                break;
        }

        if (isError)
        {
            cout << "error" << "\n";
            continue;
        }

        cout << "[";
        int numberCount = que.size();
        int search = !isReversed ? 0 : numberCount - 1;

        for (;
             (!isReversed && search < numberCount) || (isReversed && search >= 0);
             !isReversed ? search++ : search--)
        {
            if ((!isReversed && search == numberCount - 1) || (isReversed && search == 0))
                cout << que[search];
            else
                cout << que[search] << ",";
        }
        cout << "]" << "\n";
    }

    return 0;
}