#include <iostream>
#include <stack>

// ref: https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x05/solutions/1874.cpp
// 솔직히 문제도 제대로 이해 못함..
using namespace std;

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    stack<int> su;
    string str;

    int count, cor = 1;
    cin >> count;

    for(int loop = 0; loop < count; loop++)
    {
        int current; cin >> current;

        while (cor <= current)
        {
            su.push(cor++);
            str += "+\n";
        }

        if(su.top() != current)
        {
            cout << "NO";
            return 0;
        }

        su.pop();
        str += "-\n";
    }

    cout << str;

    return 0;
}