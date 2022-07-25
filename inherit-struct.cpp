// what if inherit struct
#include <iostream>

struct CBaseStruct
{
    int pos = 102;
};

class Test : public CBaseStruct
{
    
};

int main()
{
    // CBaseStruct test;
    Test test;
    std::cout << test.pos; // it works
    return 0;
}