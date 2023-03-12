#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int board[26][26];
bool visit[26][26];

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int n;

vector<int> areas;

void SearchArea(int y, int x)
{
    queue<pair<int, int>> que;

    que.push({y, x});
    visit[y][x] = true;

    int currentCount = 0;
    while(!que.empty())
    {
        int curY = que.front().first,
            curX = que.front().second;

        que.pop();
        currentCount++;

        for(int dir = 0; dir < 4; dir++)
        {
            int testY = curY + dy[dir];
            int testX = curX + dx[dir];

            if (0 > testY || testY >= n || 0 > testX || testX >= n) 
                continue;

            if (visit[testY][testX] || board[testY][testX] == 0)
                continue;

            visit[testY][testX] = true;
            que.push({testY, testX});
        }
    }

    areas.push_back(currentCount);
}

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    cin >> n;

    for(int yl = 0; yl < n; yl++)
    {
        string temp;
        cin >> temp;

        for (int xl = 0; xl < n; xl++)
        {
            if(temp[xl] == '1')
                board[yl][xl] = 1;
        }
    }

    for (int yl = 0; yl < n; yl++)
    {
        for (int xl = 0; xl < n; xl++)
        {
            if (!visit[yl][xl] && board[yl][xl] == 1)
            {
                SearchArea(yl, xl);
            }   
        }
    }

    sort(areas.begin(), areas.end());

    int count = areas.size();
    cout << count << "\n";

    for (int i = 0; i < count; i++)
    {
        cout << areas[i] << "\n";
    }

    return 0;
}