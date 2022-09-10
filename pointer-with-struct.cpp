#include <iostream>

using namespace std;

struct Test
{
    char data;
    Test *left;
};

int main()
{
    Test *mytest = new Test,
        *myleft = new Test;

    mytest->data = '0';
    cout << mytest->data;

    mytest->left = myleft;
    myleft->data = 'Y';

    cout << (mytest->left)->data;

    delete mytest;
    delete myleft;

    return 0;
}