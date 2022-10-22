#include <iostream>
#include <stack>

using namespace std;

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int count; cin >> count;
    int answer = 0;

    for(int loop = 0; loop  < count; loop++)
    {
        string command; cin >> command;

        stack<char> chk;
        for (auto &&i : command)
        {
            if(chk.empty() || chk.top() != i)
                chk.push(i);
            else
                chk.pop();
        }
        
        if(chk.empty())    answer++;
    }

    cout << answer;
    return 0;
}