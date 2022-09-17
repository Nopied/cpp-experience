#include <iostream>

// TIMEOUT
// didn't expect 80000 ^ 2 case

using namespace std;

int tower[80001];

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    long long answer = 0; // OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOW
    int count; cin >> count;

    for(int loop = 1; loop <= count; loop++)
    {
        cin >> tower[loop];
    }

    for(int loop = count; loop > 0; loop--)
    {
        int current = tower[loop];

        for (int search = loop + 1; search <= count; search++)
        {
            int check = tower[search];
            if (current <= check)
                break;

            answer++;
        }
    }
    
    cout << answer;

    return 0;
}