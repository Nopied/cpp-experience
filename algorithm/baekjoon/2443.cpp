#include <iostream>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int count; std::cin >> count;
    int maxStrLen = (2 * count) - 1;

    for(int loop = 0; loop < count; loop++)
    {
        std::string str;
        for (int strIndex = 0; strIndex < maxStrLen; strIndex++)
        {
            if (strIndex < loop)
                str += " ";
            else if (maxStrLen - (loop + 1) < strIndex)
            // 문자열 뒤의 공백을 넣으면 "출력 형식이 잘못되었습니다." 오답 처리됨 
                continue;
            else
                str += "*";
        }

        std::cout << str;
        std::cout << "\n";
    }

    return 0;
}