#include <iostream>

// ref: https://blog.encrypted.gg/943

using namespace std;
using ll = long long;

ll solve(ll a, ll b, ll c)
{
    if (b == 1)
        return a % c;

    ll val = solve(a, b/2, c);
    val = val * val % c;

    if(b%2 == 0)
        return val;

    return val * a % c;
}

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    ll a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b, c);

    return 0;
}