#include <iostream>
#include <stack>
#include <utility>

using namespace std;

#define X first
#define Y second

// ref: https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x05/solutions/3015.cpp

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int count; cin >> count;

    long long answer = 0;
    stack<pair<int, int>> chtk;

    while(count-- > 0)
    {
        int current; cin >> current;
        int iMin = 1;

        while (!chtk.empty() && chtk.top().X <= current)
        {
            answer += chtk.top().Y;

            if(chtk.top().X == current)
                iMin += chtk.top().Y;
            
            chtk.pop();
        }

        if(!chtk.empty()) answer++;
        chtk.push({current, iMin});
    }

    cout << answer;

    return 0;
}