#include <iostream>

// ref: https://blog.encrypted.gg/943
// ?? 솔직히 잘 이해가 안됨 

using namespace std;

/*
    a에서 b로 n개의 원반을 이동
*/
void solve(int a, int b, int n)
{
    // 원반은 기본적으로 하나씩만 이동함 
    if(n == 1)
    {
        cout << a << ' ' << b << '\n';
        return; 
    }

    // 6 - a - b???????????
    // 처음 호출 = 2, 기본적으로 마지막 원반을 제외하고 모두 2번째 칸으로 이동해야 옮길 수 있음
    solve(a, 6 - a - b, n - 1);
    cout << a << ' ' << b << '\n';

    // 두번째 칸에 둔 모든 원반을 세번째로 옮김
    solve(6-a-b, b, n-1);
}

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int k;
    cin >> k;

// k
/*
    1: 1
    2: 3
    3: 7
    4: 15
    5: 31
    6: 63
    7: 127
    8: 255

    "(이전 항의 이동횟수 * 2) + 1" 로도 유도 가능 
*/
    cout << (1 << k) - 1 << "\n";
    solve(1, 3, k);
    return 0;
}