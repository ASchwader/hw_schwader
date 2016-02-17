#include "llistint.h"
#include <cstdlib>
#include <stdexcept>
#include <iostream>

using namespace std;


int main()
{
    LListInt test, derp, concat, herp;
    test.insert(0,1);
    test.insert(1,2);
    test.insert(2,3);
    test.insert(3,4);
    concat.insert(0,5);
    concat.insert(1,6);
    concat.insert(2,7);
    concat.insert(3,8);
    derp = (test + concat);
    for(int i = 0; i < 8; i++)
    {
        cout << derp[i] << endl;
    }
    LListInt merp =LListInt(derp);

    for(int i = 0; i < 8; i++)
    {
        cout << merp[i] << endl;
    }






}
