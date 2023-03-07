#include <iostream>
#include <queue>

using namespace std;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int board[101][101];
bool visit[101][101];

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;

    // 1: R
    // 2: G
    // 3: B

    for(int yLoop = 0; yLoop < n; yLoop++)
    {
        fill(visit[yLoop], visit[yLoop] + 101, false);

        string temp;
        cin >> temp;   

        for (int xLoop = 0; xLoop < n; xLoop++)
        {
            if (temp[xLoop] == 'R')
                board[yLoop][xLoop] = 1;
            else if (temp[xLoop] == 'G')
                board[yLoop][xLoop] = 2;
            else if (temp[xLoop] == 'B')
                board[yLoop][xLoop] = 3;
        }
    }

    int currentColor = 0;

    int nonRB = 0;
    for (int yLoop = 0; yLoop < n; yLoop++)
    {
        for (int xLoop = 0; xLoop < n; xLoop++)
        {
            if(!visit[yLoop][xLoop])
            {
                nonRB++;
                currentColor = board[yLoop][xLoop];

                queue<pair<int, int>> que;
                que.push({yLoop, xLoop});
                visit[yLoop][xLoop] = true;

                while (!que.empty())
                {
                    int curY = que.front().first,
                        curX = que.front().second;
                    que.pop();

                    for (int dir = 0; dir < 4; dir++)
                    {
                        int testY = curY + dy[dir],
                            testX = curX + dx[dir];

                        if (testY < 0 || testY >= n || testX < 0 || testX >= n)
                            continue;

                        if (!visit[testY][testX] && board[testY][testX] == currentColor)
                        {
                            visit[testY][testX] = true;
                            que.push({testY, testX});
                        }
                    }
                }                
            }
        }
    }

    for (int yLoop = 0; yLoop < n; yLoop++)
        fill(visit[yLoop], visit[yLoop] + 101, false);

    int RB = 0;
    for (int yLoop = 0; yLoop < n; yLoop++)
    {
        for (int xLoop = 0; xLoop < n; xLoop++)
        {
            if (!visit[yLoop][xLoop])
            {
                RB++;
                currentColor = board[yLoop][xLoop];

                // cout << yLoop << " " << xLoop << "\n";

                queue<pair<int, int>> que;
                que.push({yLoop, xLoop});
                visit[yLoop][xLoop] = true;

                while (!que.empty())
                {
                    int curY = que.front().first,
                        curX = que.front().second;
                    que.pop();

                    for (int dir = 0; dir < 4; dir++)
                    {
                        int testY = curY + dy[dir],
                            testX = curX + dx[dir];

                        if (testY < 0 || testY >= n || testX < 0 || testX >= n)
                            continue;

                        if (!visit[testY][testX])
                        {
                            if ((currentColor == 1 || currentColor == 2) && board[testY][testX] == 3)
                                continue;

                            if (currentColor == 3 && 3 != board[testY][testX])
                                continue;

                            // cout << board[testY][testX] << ": " << currentColor << " " << testY << " " << testX << "\n";

                            visit[testY][testX] = true;
                            que.push({testY, testX});
                        }
                    }
                }
            }
        }
    }

    cout << nonRB << " " << RB;

    return 0;
}