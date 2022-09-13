#include <iostream>
#include <list>

using namespace std;

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int count; cin >> count;

    for(int loop = 0; loop < count; loop++)
    {
        string str;
        cin >> str;
        list<char> li;

        auto cursor = li.begin();

        int len = str.length();
        for(int search = 0; search < len; search++)
        {
            char command = str[search];
            // cout << "command: " << command;

            switch (command)
            {
                case '<':
                {
                    if (cursor != li.begin())
                    {
                        cursor--;
                    }
                        
                    break;
                }
                case '>':
                {
                    if (cursor != li.end())
                    {
                        cursor++;
                    }
                        
                    break;
                }
                case '-':
                {
                    if (cursor != li.begin())
                    {
                        cursor--;
                        cursor = li.erase(cursor);
                    }
                    
                    break;
                }
                default:
                {
                    li.insert(cursor, command);   

                    break;
                }
            }
        }

        for(auto loop : li)
            cout << loop;

        cout << "\n";
    }

    return 0;
}