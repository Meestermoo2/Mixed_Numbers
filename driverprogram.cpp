#include <iostream>
#include "mixednumber.h"
#include <iomanip>

using namespace std;

bool driverProgram()
{
    try {
        std::stringstream ss;
        string temp;

        mixedNumber a, b;
        while(1)
        {
            cout << "Please Enter a mixed number: ";
            cin >> a;
            cout << "Please Enter a mixed number: ";
            cin >> b;
            cout << "You Entered the mixed number: " << a << " and " << b <<endl << endl;

            cout << "A+B = " << a+b << endl;
            cout << "A-B = " << a-b << endl;
            cout << "A*B = " << a*b << endl;
            cout << "A/B = " << a/b << endl;
            cout << "B+A = " << b+a << endl;
            cout << "B-A = " << b-a << endl;
            cout << "B*A = " << b*a << endl;
            cout << "B/A = " << b/a << endl;
        }


    } catch (fraction_ERRORS e) {
        switch(e)
        {
            case DivByZero :
                cout << "Division by zero" << endl;
                break;
            case Invalid_Type :
                cout << "Invalid type was entered" << endl;
                break;
        }
    }
    catch(...)
    {
        cout << "An unknown error occurred" << endl;
    }
    cout << "Driver program has ended" << endl;

    return 1;
}
