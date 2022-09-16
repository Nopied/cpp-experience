#include <iostream>
// #include <stack>
#include <list>

using namespace std;

// TIMEOUT

int tower[500001];
int result[500001] = {0};

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    list<int> chst;
    int count; cin >> count;

    for(int loop = 1; loop <= count; loop++)
    {
        cin >> tower[loop];
    }

    for (int loop = count; loop > 0; loop--)
    {
        for (list<int>::iterator search = chst.begin(); search != chst.end(); )
        {
            if (tower[loop] > tower[*search])
            {
                result[*search] = loop;
                search = chst.erase(search);
            }
            else
                search++;
        }         

        chst.push_back(loop);
    }

    for (int loop = 1; loop <= count; loop++)
    {
        cout << result[loop] << " ";
    }

    return 0;
}