#include <iostream>
#include "mixednumber.h"
#include <iomanip>

using namespace std;

bool driverProgram()
{
    try {
//        std::stringstream ss;
//        fraction a;
//        string temp;

//        mixedNumber a(3,2,3), b(4.0), c;
    //    cout<<"a = "<<a<<" b = "<<b<<endl;
    //    c = a + b;
    //    cout<<"c = "<<c<<endl;
//        cout<<"a = "<<a<<" b = "<<b<<" c = "<<c<<endl;
//        a = -3.25;
//        cout<<"a = "<<a<<" b = "<<b<<" c = "<<c<<endl;
//        b = 4/5.;
//        cout<<"a = "<<a<<" b = "<<b<<" c = "<<c<<endl;
//        c = a + b;
//        cout<<"a = "<<a<<" b = "<<b<<" c = "<<c<<endl;
//        cout << "We got to the end" << endl;
//        return 0;


        mixedNumber a;
        while(1)
        {
            cout << "Enter a mixed number" << endl;
            cin >> a;
            cout << a << endl;
        }

//        temp = "1 / 2";
//        ss << temp;
//        ss >> a;
//        cout << "Input: " << temp  << endl << "Output: "<< a << endl << endl;

//        ss.clear();
//        temp = "+3/4";
//        ss << temp;
//        ss >> a;
//        cout << "Input: " << temp  << endl << "Output: "<< a << endl << endl;

//        temp = "-.5";
//        ss.clear();
//        ss << temp;
//        ss >> a;
//        cout << "Input: " << temp  << endl << "Output: "<< a << endl << endl;

//        temp = "-4/5";
//        ss.clear();
//        ss << temp;
//        ss >> a;
//        cout << "Input: " << temp  << endl << "Output: "<< a << endl << endl;

//        temp = "5/0";
//        ss.clear();
//        ss << temp;
//        ss >> a;
//        cout << "Input: " << temp  << endl << "Output: "<< a << endl << endl;

//        temp = "-2/3";
//        ss.clear();
//        ss << temp;
//        ss >> a;
//        cout << "Input: " << temp  << endl << "Output: "<< a << endl << endl;

//        while(1)
//        {
//        cout << "Input a fraction" << endl;
//        cin >> a;
//        cout << "Output: "<< a << endl << endl;
//        }

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
