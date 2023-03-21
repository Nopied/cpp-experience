#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// ???? 이거 진짜 어디가 틀린지 모르겠음
// 예제는 모두 통과

// 시도한 반례
/*
In:
2
1 1
1 1

Out: 1 (정답
ㅛㅅ)
*/

int board[101][101];
bool visit[101][101];

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int n;

int maxCount = 1;
int currentCount = 0;

void SearchArea(int test, int y, int x)
{
    queue<pair<int, int>> que;

    que.push({y, x});
    visit[y][x] = true;

    while(!que.empty())
    {
        int curY = que.front().first,
            curX = que.front().second;

        que.pop();

        for(int dir = 0; dir < 4; dir++)
        {
            int testY = curY + dy[dir];
            int testX = curX + dx[dir];

            if (0 > testY || testY >= n || 0 > testX || testX >= n) 
                continue;

            if (visit[testY][testX] || board[testY][testX] <= test)
                continue;

            visit[testY][testX] = true;
            que.push({testY, testX});
        }
    }
}

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    cin >> n;

    for(int yl = 0; yl < n; yl++)
    {
        for (int xl = 0; xl < n; xl++)
        {
            cin >> board[yl][xl];
        }
    }

    for(int test = 0; test < 10; test++)
    {
        for (int yl = 0; yl < n; yl++)
        {
            fill(visit[yl], visit[yl] + 101, false);
        }

        currentCount = 0;

        for (int yl = 0; yl < n; yl++)
        {
            for (int xl = 0; xl < n; xl++)
            {
                if (!visit[yl][xl] && board[yl][xl] > test)
                {
                    currentCount++;
                    SearchArea(test, yl, xl);
                }
            }
        }

        maxCount = max(currentCount, maxCount);
    }

    cout << maxCount;
    return 0;
}