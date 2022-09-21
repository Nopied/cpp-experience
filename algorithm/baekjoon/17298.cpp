#include <iostream>
#include <stack>
#include <utility>
#include <algorithm>

// no ref. YAY!

using namespace std;

int numbers[1000001] = {-1};

#define index first
#define su second

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    fill_n(numbers, 1000001, -1);
    stack<pair<int, int>> chtk;

    int count; cin >> count;

    for (int loop = 0; loop < count; loop++)
    {
        int current; cin >> current;

        while (!chtk.empty() && chtk.top().su < current)
        {
            numbers[chtk.top().index] = current;
            chtk.pop();
        }

        chtk.push({loop, current});
    }

    for (int loop = 0; loop < count; loop++)
    {
        cout << numbers[loop] << " ";
    }

    return 0;
}