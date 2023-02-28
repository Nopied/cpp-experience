#include <iostream>
#include <queue>

int dis[101][101] = {0};
bool isWall[101][101];

int yd[4] = {1, 0, -1, 0};
int xd[4] = {0, 1, 0, -1};

using namespace std;

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int y, x;
    cin >> y >> x;

    for(int yi = 0; yi < 101; yi++)
    {
        fill(isWall[yi], isWall[yi] + 101, true);
    }
    

    for(int yi = 0; yi < y; yi++)
    {
        string temp;
        cin >> temp;

        // cout << temp << "\n";

        for(int xi = 0; xi < x; xi++)
        {
            if(temp[xi] == '1')
                isWall[yi][xi] = false;
            else
                isWall[yi][xi] = true;

            dis[yi][xi] = -1;
        }
    }

    dis[0][0] = 0;
    queue<pair<int, int>> que;
    que.push({0, 0});

    while(!que.empty())
    {
        int curY = que.front().first, curX = que.front().second;
        que.pop();

        for(int dirTest = 0; dirTest < 4; dirTest++)
        {
            int testY = curY + yd[dirTest],
                testX = curX + xd[dirTest];
            if (!isWall[testY][testX] && dis[testY][testX] == -1)
            {
                dis[testY][testX] = dis[curY][curX] + 1;
                que.push({testY, testX});
            }
        }
    }

    cout << dis[y - 1][x - 1] + 1;

/*
    cout << "\n";
    for (int yi = 0; yi < 101; yi++)
    {
        for (int xi = 0; xi < 101; xi++)
        {
            if (isWall[yi][xi])
            {
                cout << "X";
            }
            else
                cout << dis[yi][xi];
        }
        cout << "\n";
    }
    cin >> y >> x;
*/

    return 0;
}