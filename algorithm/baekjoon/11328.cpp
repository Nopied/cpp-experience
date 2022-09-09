#include <iostream>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int count; std::cin >> count;
    for(int loop = 0; loop < count; loop++)
    {
        int letter[26] = {0}, guess[26] = {0};
        bool check = true;

        std::string str; std::cin >> str;
        int len = str.length();
        for(int search = 0; search < len; search++)
        {
            letter[str[search] - 97]++;
        }

        std::cin >> str;
        len = str.length();
        for (int search = 0; search < len; search++)
        {
            guess[str[search] - 97]++;
        }

        for (int search = 0; search < 26; search++)
        {
            if(letter[search] != guess[search])
            {
                check = false;
                break;
            }
        }

        if (check)
            std::cout << "Possible" << "\n";
        else
            std::cout << "Impossible"<< "\n";
    }

    return 0;
}