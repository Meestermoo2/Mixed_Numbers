#include <iostream>
#include "mixednumber.h"
#include "driverprogram.cpp"
#include "superswitch.cpp"

using namespace std;

int main()
{
//    driverProgram();
    while (1)
    {
        try
        {
            while(1){
                mixedNumber a(0),b(0);
                char junk;
                std:stringstream ss;

                string temp;
                cin >> temp;

                ss << temp;
                ss >> a;

                if (!(ss >> junk))
                    cout << "a = "<<a<<endl;
                else{
                    ss >> b;

                    switch (junk)
                    {
                    case '+':
                        cout << "a+b = " << a+b << endl;
                        break;
                    case '-':
                        cout << "a-b = " << a-b << endl;
                        break;
                    case '*':
                        cout << "a*b = " << a*b << endl;
                        break;
                    case '/':
                        cout << "a/b = " << a/b << endl;
                        break;
                    default:
                        cout << endl;
                    }
                }
                ss.clear();
            }
        }
        catch (fraction_ERRORS e) {
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

    }


    return 0;
}

/*Sample Program
 * Please Enter a mixed number: 5/4
You Entered the mixed number: 1 1/4

Please Enter a mixed number: 11/4
You Entered the mixed number: 2 3/4

Please Enter a mixed number: 5
You Entered the mixed number: 5

Please Enter a mixed number: 1234
You Entered the mixed number: 1234

Please Enter a mixed number: 5.55
You Entered the mixed number: 5 5/9

Please Enter a mixed number: 5.5
You Entered the mixed number: 5 1/2

Please Enter a mixed number: -.5
You Entered the mixed number: -1/2

Please Enter a mixed number: a/4
Invalid type was entered
Driver program has ended
Press <RETURN> to close this window...
*/
