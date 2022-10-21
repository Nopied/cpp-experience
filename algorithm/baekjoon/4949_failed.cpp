#include <iostream>
#include <stack>

// Why is this failed? WHY???
using namespace std;

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    string command;

    while (1)
    {
        stack<char> stk;
        getline(std::cin, command);

        if (command == ".")
            break;

        int len = command.length();
        for (int loop = 0; loop < len; loop++)
        {
            if (command[loop] == '(' || command[loop] == '[')
                stk.push(command[loop]);

            else if (command[loop] == ')' || command[loop] == ']')
            {
                if(stk.empty())
                {
                    stk.push('F');
                    break;
                }

                if (stk.top() == '(' && command[loop] == ')')
                    stk.pop();
                else if (stk.top() == '[' && command[loop] == ']')
                    stk.pop();
            }       
        }

        if (stk.empty())
            cout << "yes" << "\n";
        else 
            cout << "no" << "\n";
    }

    return 0;
}