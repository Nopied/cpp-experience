#include <iostream>
#include <queue>

using namespace std;

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int x, y; cin >> y >> x;
    int block[501][501] = {0};
    bool checked[501][501] = {false};

    int count = 0, maxArea = 0;

    for(int yLoop = 0; yLoop < y; yLoop++)
    {
        for (int xLoop = 0; xLoop < x; xLoop++)
        {
            cin >> block[yLoop][xLoop];
        }
    }

    for (int yLoop = 0; yLoop < y; yLoop++)
    {
        for (int xLoop = 0; xLoop < x; xLoop++)
        {
            if (block[yLoop][xLoop] > 0 && !checked[yLoop][xLoop])
            {
                int currentArea = 0;
                count++;

                // cout << "found " << yLoop << " " << xLoop << "\n";

                queue<pair<int, int>> que;
                que.push({yLoop, xLoop});

                // cout << "Entering " << yLoop << " " << xLoop << "\n";

                while(!que.empty())
                {
                    currentArea++;
                    
                    int curX = que.front().second, curY = que.front().first;

                    // cout << "Checking " << curY << " " << curX << "\n";
                    checked[curY][curX] = true;

                    if (0 <= (curX - 1) && block[curY][curX - 1] > 0 && !checked[curY][curX - 1])
                    {
                        checked[curY][curX - 1] = true;
                        que.push({curY, curX - 1});
                    }

                    if (x > (curX + 1) && block[curY][curX + 1] > 0 && !checked[curY][curX + 1])
                    {
                        checked[curY][curX + 1] = true;
                        que.push({curY, curX + 1});
                    }

                    if (0 <= (curY - 1) && block[curY - 1][curX] > 0 && !checked[curY - 1][curX])
                    {
                        checked[curY - 1][curX] = true;
                        que.push({curY - 1, curX});
                    }

                    if (y > (curY + 1) && block[curY + 1][curX] > 0 && !checked[curY + 1][curX])
                    {
                        checked[curY + 1][curX] = true;
                        que.push({curY + 1, curX});
                    }

                    que.pop();
                }

                maxArea = max(currentArea, maxArea);
            }
        }
    }

    cout << count << "\n"
         << maxArea;

    return 0;
}