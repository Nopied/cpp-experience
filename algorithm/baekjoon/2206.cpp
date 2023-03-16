// ref: https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x09/solutions/2206.cpp

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

#define X first
#define Y second

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

char board[1000][1000];
int dis[1000][1000][2];
// [x][y][z]
// z = 0: 하나도 부수지 않은 경우
// z = 1: 하나 부순 경우

int yli, xli;

bool IsInOBB(int y, int x)
{
    return !(0 > y || y >= yli || 0 > x || x >= xli);
}

int bfs()
{
    for(int yl = 0; yl < yli; yl++)
        for (int xl = 0; xl < xli; xl++)
            dis[yl][xl][0] = dis[yl][xl][1] = -1;

    dis[0][0][0] = dis[0][0][1] = 1;

    queue<tuple<int, int, int>> que;
    que.push({0, 0, 0});

    while(!que.empty())
    {
        int y, x, pix;
        tie(y, x, pix) = que.front();
        if(y == yli - 1 && x == xli - 1)
            return dis[y][x][pix];
        que.pop();
        
        int nextDist = dis[y][x][pix] + 1;
        for(int dir = 0; dir < 4; dir++)
        {
            int ty = y + dy[dir],
                tx = x + dx[dir];

            if (!IsInOBB(ty, tx))
                continue;

            if(board[ty][tx] == '0' && dis[ty][tx][pix] == -1)
            {
                dis[ty][tx][pix] = nextDist;
                que.push({ty, tx, pix});
            }

            // 방식은 비슷했는데 이 부분이 조금 다름
            // 그냥 배열로 경우의 수 나눠도 메모리 초과 안됨
            if(!pix && board[ty][tx] == '1' && dis[ty][tx][1] == -1)
            {
                dis[ty][tx][1] = nextDist;
                que.push({ty, tx, 1});
            }
        }
    }

    return -1;
}

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    cin >> yli >> xli;
    for(int yl = 0; yl < yli; yl++)
    {
        for(int xl = 0; xl < xli; xl++)
        {
            cin >> board[yl][xl];
        }
    }

    cout << bfs();

    return 0;
}