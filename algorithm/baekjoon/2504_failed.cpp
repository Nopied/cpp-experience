#include <iostream>
#include <stack>

using namespace std;
// FAILED, this one has many problems.

#define index first
#define value second

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    string command;
    cin >> command;

    stack<pair<int, char>> stk;
    stack<int> ans;

    int len = command.length();

    int currentRoot = -1;
    int rootFormula[16];
    fill_n(rootFormula, 16, 0);

    bool isMin = true;

    for (int loop = 0; loop < len; loop++)
    {
        if (command[loop] == '(' || command[loop] == '[')
        {
            isMin = true;
            if(stk.empty())
                currentRoot++;            
            
            stk.push({loop, command[loop]});
        }

        else if (command[loop] == ')' || command[loop] == ']')
        {
            if (stk.top().value == '(' && command[loop] == ')')
            {
                stk.pop();

                cout << "popped at " << loop << ", isMin: " << (isMin ? "true" : "false") << "\n";
                if (isMin)
                {
                    rootFormula[currentRoot] += 2;
                }
                else
                {
                    rootFormula[currentRoot] *= 2;
                }

                isMin = false;
            }
                
            else if (stk.top().value == '[' && command[loop] == ']')
            {
                stk.pop();

                cout << "popped at " << loop << ", isMin: " << (isMin ? "true" : "false") << "\n";
                if (isMin)
                {
                    rootFormula[currentRoot] += 3;
                }
                else
                {
                    rootFormula[currentRoot] *= 3;
                }

                isMin = false;
            }
        }       
    }

    if(stk.empty())
    {
        int answer = 0;
        
        for (auto &&i : rootFormula)
        {
            cout << "Added " << i << "\n";
            answer += i;
        }

        cout << answer;
    }
    else
        cout << "0";
    return 0;
}