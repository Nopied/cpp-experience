#include <iostream>
#include <queue>

using namespace std;

int dis[301][301];

int dy[8] = {2, 2, 1, -1, -2, -2, -1, 1};
int dx[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int count;
    cin >> count;

    for (int test = 0; test < count; test++)
    {
        int s;
        cin >> s;

        for(int y = 0; y < s; y++)
        {
            fill(dis[y], dis[y]+s, -1);
        }

        queue<pair<int, int>> que;

        int x, y;
        cin >> x >> y;

        que.push({y, x});
        dis[y][x] = 0;

        int desX, desY;
        cin >> desX >> desY;

        while (!que.empty())
        {
            int curY = que.front().first,
                curX = que.front().second;
            que.pop();

            if (curY == desY && curX == desX)
            {
                cout << dis[curY][curX] << "\n";
                // cout << "DONE" << "\n";
                break;
            }

            for(int dir = 0; dir < 8; dir++)
            {
                int testY = curY + dy[dir],
                    testX = curX + dx[dir];

                if (testY < 0 || testY >= s || testX < 0 || testX >= s)
                    continue;

                if (dis[testY][testX] != -1)
                    continue;

                que.push({testY, testX});
                dis[testY][testX] = dis[curY][curX] + 1;
            }
        }

        // cout << dis[desY][desX] << "\n";
    }

    return 0;
}