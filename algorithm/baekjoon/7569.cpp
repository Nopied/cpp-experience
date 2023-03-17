#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int board[101][101][101];
bool visit[101][101][101];

int dz[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {1, 0, -1, 0, 0, 0};
int dx[6] = {0, 1, 0, -1, 0, 0};

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int xl, yl, zl;
    cin >> xl >> yl >> zl;

    for(int z = 0; z < zl; z++)
    {
        for (int y = 0; y < yl; y++)
        {
            fill(board[z][y], board[z][y] + 101, -1);
            fill(visit[z][y], visit[z][y] + 101, false);
        }
    }

    queue<tuple<int, int, int>> que;
    int temp;
    bool needTest = false;

    for (int z = 0; z < zl; z++)
    {
        for (int y = 0; y < yl; y++)
        {
            for (int x = 0; x < xl; x++)
            {
                cin >> temp;
                board[z][y][x] = temp;

                if (temp == 1)
                {
                    que.push(make_tuple(z, y, x));
                    visit[z][y][x] = true;
                }
                else if(temp == 0)
                    needTest = true;
            }
        }
    }
    
    int day = 0;

    if(!needTest)
    {
        cout << 0;
        return 0;
    }

    int dayCount = que.size();
    while (dayCount != 0)
    {
        day++;
        dayCount = que.size();

        for (int t = 0; t < dayCount; t++)
        {
            tuple<int, int, int> tup = que.front();
            int curZ = get<0>(tup),
                curY = get<1>(tup),
                curX = get<2>(tup);
            que.pop();

            for (int dir = 0; dir < 6; dir++)
            {
                int testZ = curZ + dz[dir],
                    testY = curY + dy[dir],
                    testX = curX + dx[dir];

                if (testZ < 0 || testZ >= zl 
                    || testY < 0 || testY >= yl 
                    || testX < 0 || testX >= xl)
                    continue;

                if (!visit[testZ][testY][testX] 
                    && board[testZ][testY][testX] != -1)
                {
                    que.push(make_tuple(testZ, testY, testX));

                    // cout << day << ": " << testZ << " " <<  testY << " " << testX << "\n";

                    board[testZ][testY][testX] = 1;
                    visit[testZ][testY][testX] = true;
                }
            }
        }

        bool keepTest = false;
        for (int z = 0; z < zl; z++)
        {
            if (keepTest)
                break;    

            for (int y = 0; y < yl; y++)
            {
                if (keepTest)
                    break;

                for (int x = 0; x < xl; x++)
                {
                    if (board[z][y][x] == 0)
                    {
                        keepTest = true;
                        break;
                    }
                }
            }
        }

        if (!keepTest)
            break;
    }

    for (int z = 0; z < zl; z++)
    {
        for (int y = 0; y < yl; y++)
        {
            for (int x = 0; x < xl; x++)
            {
                if (board[z][y][x] == 0)
                {
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    cout << day;
    return 0;
}