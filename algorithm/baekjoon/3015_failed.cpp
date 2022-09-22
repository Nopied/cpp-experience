#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// very very wrong

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int count; cin >> count;
    long long answer = 0;
    
    vector<deque<int>> v;

    v.push_back(deque<int>());
    if(count == 1)
    {
        cout << "0";
        return 0;
    }

    for (int loop = 0; loop < count; loop++)
    {
        int current; cin >> current;

        auto cursor = v[0].end();
        while (v[0].size() > 0 && cursor != v[0].begin())
        {
            if (*cursor > v[0].front() || *cursor > current)
            {
                v[0].pop_front();
                answer += v[0].size();

                break;
            }

            cursor--;
        }
        v[0].push_back(current);
    }

    // cout << "re: " << v[0].size();
    // 남은 것들을 위처럼 처리
    
    int rec = 1, len, prelen = -1;
    while(v[rec - 1].size() > 2)
    {
        v.push_back(deque<int>());
        int len = v[rec - 1].size();

        for (int loop = 0; loop < len; loop++)
        {
            int current = v[rec - 1].front();
            v[rec - 1].pop_front();

            auto cursor = v[rec].end();
            while (v[rec].size() > 0 && cursor != v[rec].begin())
            {
                if (*cursor > v[rec].front() || *cursor > current)
                {
                    v[rec].pop_front();
                    answer += v[rec].size();
                    break;
                }

                cursor--;
            }
            v[rec].push_back(current);
        }

        if (len == prelen)
        {
            answer += 2;
            break;
        }

        prelen = v[rec].size();
        rec++;
    }

    answer++;
    cout << answer;

    return 0;
}