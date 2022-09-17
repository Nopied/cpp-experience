#include <iostream>
#include <stack>

// ref: https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x05/solutions/6198.cpp
// *sigh*

using namespace std;

int tower[80001];

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    stack<int> chsk;
    long long answer = 0; // OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOW
    int count; cin >> count;

    int current;
    while(count--)
    {
        cin >> current;

        while (!chsk.empty() && chsk.top() <= current)
            chsk.pop();

        answer += chsk.size();
        cout << "added " << chsk.size() << "\n";

        chsk.push(current);
    }
    
    cout << answer;

    return 0;
}