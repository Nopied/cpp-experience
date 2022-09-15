#include <iostream>
#include <queue>

using namespace std;

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    queue<int> que;

    int count, gap;
    cin >> count >> gap;

    for(int loop = 1; loop <= count; loop++)
        que.push(loop);

    cout << "<";

    while(!que.empty())
    {
        for(int loop = 1; loop <= gap; loop++)
        {
            if(loop == gap)
            {
                cout << que.front();
            }
            else
            {
                que.push(que.front());
            }
            
            que.pop();
        }

        if(que.size() > 0)
            cout << ", ";
    }

    cout << ">";

    return 0;
}