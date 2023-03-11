#include <iostream>
#include <queue>

int dis[1001][1001] = {0};
bool isWall[1001][1001];
bool isFire[1001][1001];

int yd[4] = {1, 0, -1, 0};
int xd[4] = {0, 1, 0, -1};

using namespace std;

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int test;
    cin >> test;

    for(int t = 0; t < test; t++)
    {
        int y, x;
        cin >> x >> y;

        queue<pair<int, int>> que, fireQue;

        for (int yi = 0; yi < 1001; yi++)
        {
            fill(isWall[yi], isWall[yi] + 1001, true);
            fill(isFire[yi], isFire[yi] + 1001, false);
            fill(dis[yi], dis[yi] + 1001, -1);
        }

        for (int yi = 0; yi < y; yi++)
        {
            string temp;
            cin >> temp;

            // cout << temp << "\n";

            for (int xi = 0; xi < x; xi++)
            {
                if (temp[xi] == '.')
                    isWall[yi][xi] = false;
                else if (temp[xi] == '@')
                {
                    isWall[yi][xi] = false;
                    dis[yi][xi] = 0;
                    que.push({yi, xi});
                }
                else if (temp[xi] == '*')
                {
                    isWall[yi][xi] = false;
                    isFire[yi][xi] = true;
                    fireQue.push({yi, xi});
                }
                else
                    isWall[yi][xi] = true;
            }
        }

        bool keepTest = true;

        while (!que.empty())
        {
            int currentCount = que.size();

            for (int loop = 0; loop < currentCount; loop++)
            {
                if (!keepTest)
                    break;

                int curY = que.front().first, curX = que.front().second;
                que.pop();

                if (isFire[curY][curX])
                    continue;

                // cout << curY << " " << curX << "\n";
                for (int dirTest = 0; dirTest < 4; dirTest++)
                {
                    int testY = curY + yd[dirTest],
                        testX = curX + xd[dirTest];

                    if (testY >= y || testY < 0 || testX >= x || testX < 0)
                    {
                        cout << dis[curY][curX] + 1 << "\n";
                        keepTest = false;
                        break;
                    }

                    if (!isFire[testY][testX] && dis[testY][testX] == -1)
                    {
                        // cout << "test: " << testY << " " << testX << "\n";

                        if (!isWall[testY][testX])
                        {
                            dis[testY][testX] = dis[curY][curX] + 1;
                            que.push({testY, testX});
                        }
                        // else if (isWall[testY][testX])
                        // {
                        //     cout << testY << " " << testX << "\n";
                        // }
                    }
                }
            }

            if (!keepTest)
                break;

            int currentFireCount = fireQue.size();
            for (int loop = 0; loop < currentFireCount; loop++)
            {
                int fireY = fireQue.front().first, fireX = fireQue.front().second;
                fireQue.pop();

                for (int dirTest = 0; dirTest < 4; dirTest++)
                {
                    int testY = fireY + yd[dirTest],
                        testX = fireX + xd[dirTest];

                    if (!isFire[testY][testX])
                    {
                        if (testY >= y || testY < 0 || testX >= x || testX < 0)
                        {
                            continue;
                        }
                        else if (!isWall[testY][testX])
                        {
                            isFire[testY][testX] = true;
                            fireQue.push({testY, testX});
                        }
                    }
                }
            }
        }

        if (keepTest)
            cout << "IMPOSSIBLE"
                 << "\n";
    }

    

    /*
    cout << "\n";
    for (int yi = 0; yi < 1001; yi++)
    {
        for (int xi = 0; xi < 1001; xi++)
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