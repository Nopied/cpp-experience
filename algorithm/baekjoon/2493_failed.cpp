#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// TIMEOUT

int tower[500001];
int result[500001] = {0};

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    queue<int> chst;
    int count; cin >> count;

    for(int loop = 1; loop <= count; loop++)
    {
        cin >> tower[loop];
    }

    for (int loop = count; loop > 0; loop--)
    {
        int count = chst.size();
        while (count--)
        {
            if (tower[loop] > tower[chst.front()])
            {
                result[chst.front()] = loop;
                chst.pop();
            }
            else
            {
                chst.push(chst.front());
                chst.pop();
            }
        }

        chst.push(loop);
    }

    for (int loop = 1; loop <= count; loop++)
    {
        cout << result[loop] << " ";
    }

    return 0;
}