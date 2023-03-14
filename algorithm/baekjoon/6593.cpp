#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dz[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {1, 0, -1, 0, 0, 0};
int dx[6] = {0, 1, 0, -1, 0, 0};

int dis[31][31][31];
bool IsWall[31][31][31];

int gz, gy, gx;

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int l = 1, y, x;

    while (l != 0)
    {
        cin >> l >> y >> x;

        if (l == 0)
            break;

        for (int zl = 0; zl < l; zl++)
        {
            for (int yl = 0; yl < y; yl++)
            {
                fill(dis[zl][yl], dis[zl][yl] + 31, -1);
                fill(IsWall[zl][yl], IsWall[zl][yl] + 31, false);
            }
        }

        queue<tuple<int, int, int>> que;

        for (int zl = 0; zl < l; zl++)
        {
            for (int yl = 0; yl < y; yl++)
            {
                string temp;
                cin >> temp;

                for (int xl = 0; xl < x; xl++)
                {
                    if(temp[xl] == 'S')
                    {
                        dis[zl][yl][xl] = 0;
                        que.push({zl, yl, xl});
                    }
                    else if (temp[xl] == 'E')
                    {
                        gz = zl, gy = yl, gx = xl;
                    }
                    else if(temp[xl] == '#')
                        IsWall[zl][yl][xl] = true;
                }
            }
        }

        bool IsGoal = false;
        while (!que.empty())
        {
            tuple<int, int, int> tup = que.front();
            int curZ = get<0>(tup),
                curY = get<1>(tup),
                curX = get<2>(tup);
            que.pop();

            if (gz == curZ && gy == curY && gx == curX)
            {
                IsGoal = true;
                break;
            }

            for (int dir = 0; dir < 6; dir++)
            {
                int testZ = curZ + dz[dir],
                    testY = curY + dy[dir],
                    testX = curX + dx[dir];

                if (testZ < 0 || testZ >= l
                    || testY < 0 || testY >= y
                    || testX < 0 || testX >= x)
                    continue;

                if (dis[testZ][testY][testX] != -1
                    || IsWall[testZ][testY][testX])
                    continue;

                dis[testZ][testY][testX] = dis[curZ][curY][curX] + 1;
                que.push({testZ, testY, testX});
            }
        }

        if(IsGoal)
            cout << "Escaped in " << dis[gz][gy][gx] << " minute(s).\n";
        else
            cout << "Trapped!\n";
    }

    return 0;
}