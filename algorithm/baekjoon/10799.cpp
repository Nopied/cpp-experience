#include <iostream>
#include <stack>

using namespace std;

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    stack<int> chk;
    string command; cin >> command;

    int answer = 0;
    int len = command.length();
    for (int loop = 0; loop < len; loop++)
    {
        if(command[loop] == '(')
            chk.push(loop);
        else if (chk.top() == (loop - 1))
        {
            // cout << chk.size() - 1 << "\n";

            chk.pop();
            answer += chk.size();
        }
        else
        {
            chk.pop();
            answer++; // 막대의 끝일 경우: https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x08/solutions/10799.cpp
        }
    }
    
    
    cout << answer;
    return 0;
}