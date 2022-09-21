#include <iostream>
// #include <stack>

using namespace std;

int numbers[1000001];

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    // stack<int> chtk;

    int count; cin >> count;

    for(int loop = 0; loop < count; loop++)
        cin >> numbers[loop];

    for (int loop = 0; loop < count; loop++)
    {
        int iMax = -1;

        for (int search = loop + 1; search < count; search++)
        {
            if (numbers[loop] < numbers[search])
            {
                iMax = numbers[search];
                break;
            }
        }

        cout << iMax << " ";
    }

    return 0;
}