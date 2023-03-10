#include <iostream>
#include <queue>

using namespace std;

int dis[1000001];

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;

    fill(dis, dis+1000001, -1);
    dis[s] = 0;

    queue<int> que;
    que.push(s);

    while(!que.empty())
    {
        int c = que.front();
        que.pop();

        if (c + u <= f && dis[c + u] == -1)
        {
            dis[c + u] = dis[c] + 1;
            que.push(c + u);
        }
        if (c - d > 0 && dis[c - d] == -1)
        {
            dis[c - d] = dis[c] + 1;
            que.push(c - d);
        }
    }

    if (dis[g] == -1)
        cout << "use the stairs";
    else 
        cout << dis[g];

    return 0;
}