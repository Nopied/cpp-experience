#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
// ref: https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x07/solutions/1021.cpp

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    deque<int> que;

    int queCount, count; cin >> queCount >> count;
    for (int loop = 1; loop <= queCount; loop++)
        que.push_back(loop);

    int answer = 0;
    while(count--)
    {
        int current; cin >> current;
        int index = find(que.begin(), que.end(), current) - que.begin();
        
        while(que.front() != current)
        {
            // que.size - index : 왼쪽 이동
            // que.size : uint
            if(index < que.size() - index)
            {
                que.push_back(que.front());
                que.pop_front();
            }
            else // 오른쪽 이동 
            {
                que.push_front(que.back());
                que.pop_back();
            }
            answer++;
        }
        
        que.pop_front();
    }

    cout << answer;

    return 0;
}