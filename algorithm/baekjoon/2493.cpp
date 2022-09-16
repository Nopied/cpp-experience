#include <iostream>
#include <stack>
#include <utility>

// ref: https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x05/solutions/2493.cpp

using namespace std;

#define index first
#define height second

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    stack<pair<int, int>> chst;
    int count; cin >> count;

    // 닿지 않을 높이에 비교군 생성
    chst.push({0, 100000001});

    for(int loop = 1; loop <= count; loop++)
    {
        int current; cin >> current;
        
        while(chst.top().height < current)
            chst.pop();

        cout << chst.top().index << " ";
        // 현재 위치의 탑을 넣는다. 
        chst.push(make_pair(loop, current));
    }

    return 0;
}