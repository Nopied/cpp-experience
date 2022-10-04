#include <iostream>
#include <queue>

using namespace std;

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    queue<int> que;
    int count; cin >> count;

    string command;
    while(count--)
    {
        cin >> command;

        if(command == "push")
        {
            int temp; cin >> temp;
            que.push(temp);
        }
        else if (command == "pop")
        {
            if (que.empty())
            {
                cout << "-1" << "\n";
                continue;
            }

            cout << que.front() << "\n";
            que.pop();
        }
        else if (command == "size")
        {
            cout << que.size() << "\n";
        }
        else if (command == "empty")
        {
            cout << (que.empty() ? "1" : "0") << "\n";
        }
        else if (command == "front")
        {
            if(que.empty()) {
                cout << "-1" << "\n";
                continue;
            }

            cout << que.front() << "\n";
        }
        else if (command == "back")
        {
            if (que.empty())
            {
                cout << "-1" << "\n";
                continue;
            }

            cout << que.back() << "\n";
        }
    }

    return 0;
}