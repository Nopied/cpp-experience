#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>

// 메모리 초과, 접근 자체가 잘못됨 

using namespace std;

int board[1001][1001];
bool visit[1001][1001];

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

/*
3 6

010000
010111
000110

out: 12
*/

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int y, x;
    cin >> y >> x;

    for(int yl = 0; yl < y; yl++)
    {
        string temp;
        cin >> temp;

        for (int xl = 0; xl < x; xl++)
        {
            board[yl][xl] = temp[xl] == '1' ? 1 : 0;
        }
    }

    queue<tuple<bool, int, int, int>> que;
    vector<int> dis;

    que.push({false, 0, 0, 1});
    visit[0][0] = true;

    while(!que.empty())
    {
        auto tu = que.front();

        bool pix = std::get<0>(tu);
        int cy = std::get<1>(tu),
            cx = std::get<2>(tu),
            cdis = std::get<3>(tu);

        que.pop();

        if (cy == y - 1 && cx == x - 1)
        {
            dis.push_back(cdis);
            continue;
        }

        visit[cy][cx] = true;

        for (int dir = 0; dir < 4; dir++)
        {
            int ty = cy + dy[dir],
                tx = cx + dx[dir];

            if (0 > ty || ty >= y 
                || 0 > tx || tx >= x)
                continue;

            if(visit[ty][tx])
                continue;
            
            if (ty == y - 1 && tx == x - 1)
            {
                dis.push_back(cdis + 1);
                continue;
            }

            cout << "pix: " << (pix ? "true" : "false") << ", " 
                << ty << " " << tx << " cdis: " << cdis << "\n";

            if (board[ty][tx] == 1)
                if (!pix)
                    que.push({true, ty, tx, cdis + 1});
            if (board[ty][tx] == 0)
                que.push({pix, ty, tx, cdis + 1});
        }
    }

    if(dis.size() > 0)
    {
        sort(dis.begin(), dis.end());
        cout << dis.front();
    }
    else
        cout << -1;

    return 0;
}