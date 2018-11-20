#include <iostream>
#include "mixednumber.h"

using namespace std;

int main()
{
    cout << "Quick Edit" << endl;
    mixedNumber a(3,2,3), b(4.25), c;
//    cout<<"a = "<<a<<" b = "<<b<<endl;
//    c = a + b;
//    cout<<"c = "<<c<<endl;
    cout<<"a = "<<a<<" b = "<<b<<" c = "<<c<<endl;
    a = -3.25;
    cout<<"a = "<<a<<" b = "<<b<<" c = "<<c<<endl;
    b = 4/5;
    cout<<"a = "<<a<<" b = "<<b<<" c = "<<c<<endl;
    c = a + b;
    cout<<"a = "<<a<<" b = "<<b<<" c = "<<c<<endl;
    cout << "We got to the end" << endl;
    return 0;
}
