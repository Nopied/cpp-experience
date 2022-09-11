#include <iostream>
#include <list>

// ref: https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x04/solutions/1406.cpp

using namespace std;

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    string str; cin >> str;
    list<char> li;

    for(auto loop : str)
        li.push_back(loop);

    // end of string
    auto cursor = li.end();
    int count; cin >> count;

    while (count-- > 0)
    {
        char command; cin >> command;

        switch (command)
        {
            case 'L':
            {
                if(cursor != li.begin())
                    cursor--; // __cxx11::list<char>::iterator--;
                break;
            }
            case 'D':
            {
                if (cursor != li.end())
                    cursor++; // __cxx11::list<char>::iterator++;
                break;
            }
            case 'B':
            {
                if(cursor != li.begin())
                {
                    cursor--;
                    cursor = li.erase(cursor);
                }
                break;
            }
            case 'P':
            {
                char target; cin >> target;
                li.insert(cursor, target);
            }
        }
    }

    for(auto loop : li)
        cout << loop;

    return 0;
}