#include <iostream>
#include "mixednumber.h"
#include <iomanip>

using namespace std;

bool driverProgram()
{
    std::stringstream ss;
    fraction a;
    string temp;

    temp = "1/2";
    ss << temp;
    ss >> a;
    cout << "Input: " << temp  << endl << "Output: "<< a << endl << endl;

    ss.clear();
    temp = "3/4";
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


    return 1;
}
