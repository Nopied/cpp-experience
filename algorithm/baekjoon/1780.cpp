#include <iostream>

using namespace std;

int a[3];
int board[2188][2188];

void solve(int s, int e)
{
    if(s == e)
    {
        a[1 + board[s][s]]++;
        return;
    }

    int base = board[s][s];
    for (int y = s; y < e; y++)
    {
        for (int x = s; x < e; x++)
        {
            if (board[y][x] != base)
            {
                int te = e + 1;
                int dite = te / 3;

                solve(s, dite - 1);
                solve(dite, (te - dite - 1));
                solve(te - dite, e);

                return;
            }
        }
    }

    a[1 + base]++;
}

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            cin >> board[y][x];
        }
    }

    solve(0, n-1);

    for(int i = 0; i < 0; i++)
    {
        cout << a[i] << '\n';
    }

    return 0;
}