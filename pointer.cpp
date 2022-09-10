#include <iostream>

using namespace std;

int main()
{
    int a, *b, *c, *d;

    a = 5;
    b = &a;

    cout << *b << "\n";

    c = b;
    cout << *c << "\n";

    // without declare nullptr on d, This will print "valid".
    if(d == nullptr)
        cout << "d is invaild";
    else
        cout << "d is valid";

    return 0;
}