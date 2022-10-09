#include <iostream>
#include <deque>

using namespace std;
// NO

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    deque<int> que;

    int count; cin >> count;
    for(int loop = 1; loop <= count; loop++)
        que.push_back(loop);

    cin >> count;
    int answer = 0;
    for(int loop = 0; loop < count; loop++)
    {
        int current; cin >> current;
        int left = 0, right = 1;

        auto leftCursor = que.begin();
        for(; leftCursor != que.end(); leftCursor++)
        {
            if (current == *leftCursor)
                break;
            left++;
        }

        auto rightCursor = que.end();
        for (; rightCursor != que.begin(); rightCursor--)
        {
            if (current == *rightCursor)
                break;
            right++;
        }

        cout << left << " " << right << "\n";
        answer += min(left, right);
        if (left <= right)
        {
            if(left == 0)
            {
                que.pop_front();
                continue;
            }

            for (int search = 0; search < left; search++)
            {
                int temp = que.front();
                que.pop_front();

                if (search != left - 1)
                    que.push_back(temp);
            }
        }
        else
        {
            for (int search = 0; search < right; search++)
            {
                int temp = que.back();
                que.pop_back();

                if (search != right - 1)
                    que.push_front(temp);
            }
        }
    }

    cout << answer;

    return 0;
}