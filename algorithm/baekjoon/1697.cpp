#include <iostream>
#include <queue>

using namespace std;

// ref: https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x09/solutions/1697.cpp

int dir[100001];

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    fill(dir, dir+100001, -1);

    int n, k;
    cin >> n >> k;

    queue<int> que;
    dir[n] = 0;
    que.push(n);

    // 무조건 도착한다는 가정으로 큐 체크는 안함
    while(dir[k] == -1)
    {
        int cur = que.front(); que.pop();

        for(int next : {cur+1, cur-1, cur*2})
        {
            if(next < 0 || next > 100000)
                continue;

            if(dir[next] != -1)
                continue;

            dir[next] = dir[cur] + 1;
            que.push(next);
        }
    }
    
    cout << dir[k];
    
    return 0;
}