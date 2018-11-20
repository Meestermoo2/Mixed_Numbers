#include <iostream>
#include "mixednumber.h"
#include <iomanip>

using namespace std;

enum errors{INVALID_TYPE, DIV_BY_ZERO};

bool driverProgram()
{
    std::stringstream ss;
    fraction a;
    string temp;

    temp = "-2/3";
    ss << temp;
    ss >> a;
    cout << "Input: " << temp  << endl << "Output: "<< a << endl << endl;

    ss.clear();
    temp = "-0.5";
    ss << temp;
    ss >> a;
    cout << "Input: " << temp  << endl << "Output: "<< a << endl << endl;

    temp = "-.5";
    ss.clear();
    ss << temp;
    ss >> a;
    cout << "Input: " << temp  << endl << "Output: "<< a << endl << endl;

    temp = "-4/5.0";
    ss.clear();
    ss << temp;
    ss >> a;
    cout << "Input: " << temp  << endl << "Output: "<< a << endl << endl;

    temp = "5/0";
    ss.clear();
    ss << temp;
    ss >> a;
    cout << "Input: " << temp  << endl << "Output: "<< a << endl << endl;

    temp = "-2/3";
    ss.clear();
    ss << temp;
    ss >> a;
    cout << "Input: " << temp  << endl << "Output: "<< a << endl << endl;

    try
    {
//        temp = "0/0";
//        ss.clear();
//        ss << temp;
//        ss >> a;
//        cout << "Input: " << temp  << endl << "Output: "<< a << endl << endl;


        temp = "abcdefg";
        ss.clear();
        ss << temp;
        ss >> a;
        cout << "Input: " << temp  << endl << "Output: "<< a << endl << endl;
    }
    catch (errors e)
    {
        switch(e)
        {
            case DIV_BY_ZERO:
                cout << "Division by zero has occured." << endl;
                break;
            case INVALID_TYPE:
                cout << "You entered an invalid type." << endl;
                break;
        }
    }
    catch (...)
    {
        cout << "An unknown error has occured." << endl;
    }


    return 1;
}
