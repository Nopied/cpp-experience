#include <iostream>
#include <deque>

// 1st: TIMEOUT
// 2nd ref: https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x07/solutions/11003.cpp

using namespace std;

#define index first
#define value second

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    deque<pair<int, int>> que;
    int count, range;
    cin >> count >> range;

    for(int loop = 0; loop < count; loop++)
    {
        int current; cin >> current;

        while (!que.empty() && que.back().value >= current)
            que.pop_back();

        que.push_back({loop, current});

        if(que.front().index <= loop - range)
            que.pop_front();

        cout << que.front().value << " ";
    }

    return 0;
}+