#include <iostream>
#include <queue>

using namespace std;

int board[51][51];
int visit[51][51];

// ref: https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x09/solutions/1012.cpp
// 문제에 지렁이가 이동하고 그 다음 위치에서도 해충 보호를 해준다는 말을 안함

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int y, x;

void solve(int curX, int curY)
{
    visit[curY][curX] = true;

    queue<pair<int, int>> que;
    que.push({curY, curX});

    while(!que.empty())
    {
        int lecY = que.front().first, lecX = que.front().second;
        que.pop();

        for(int dir = 0; dir < 4; dir++)
        {
            int vy = lecY + dy[dir],
                vx = lecX + dx[dir];

            if(vy < 0 || vy >= y || vx < 0 || vx >= x)
                continue;
            if(visit[vy][vx] || board[vy][vx] != 1)
                continue;

            visit[vy][vx] = true; 
            que.push({vy, vx});
        }

    }
}

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int test;
    cin >> test;

    for (int curTest = 0; curTest < test; curTest++)
    {
        for (int yLoop = 0; yLoop < 51; yLoop++)
        {
            fill(board[yLoop], board[yLoop] + 51, 0);
            fill(visit[yLoop], visit[yLoop] + 51, false);
        }

        cin >> x >> y;

        int count, res = 0;
        cin >> count;
        for (int loop = 0; loop < count; loop++)
        {
            int lecY, lecX;

            cin >> lecX >> lecY;
            board[lecY][lecX] = 1;
        }

        for(int yLoop = 0; yLoop < y; yLoop++)
        {
            for (int xLoop = 0; xLoop < x; xLoop++)
            {
                if(board[yLoop][xLoop] == 1 && !visit[yLoop][xLoop])
                {
                    solve(xLoop, yLoop);
                    res++;
                }
            }
        }

        cout << res << "\n";
    }

    return 0;
}