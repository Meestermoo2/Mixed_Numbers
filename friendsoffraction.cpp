#include "fraction.h"

std::ostream& operator<<(std::ostream& out, const fraction &frac)
{
    out<<frac.num;
    if(frac.denom != 1)
         out<<"/"<<frac.denom;
    return out;
}

std::istream& operator>>(std::istream& in, fraction &frac)
{
    char junk;
    std::stringstream ss;
    std::string possibleFraction;
    if(&in == &std::cin) //This means that the program is reading from the console
    {
        if(in>>possibleFraction)
        {
            if(possibleFraction.find_first_not_of("-+0123456789./") < possibleFraction.size())
            {
                throw Invalid_Type;
            }
            ss<<possibleFraction;
            ss>>frac;
        }
    }
    else//Let's assume everything else is a file (for now)
    {        
        // Negative check, this will allow us to change the possibleFraction into its negative counterpart.
        bool neg = false;
        if (in.peek() == '-')
        {
            in >> junk;
            neg = true;
        }

        // Input the possiblefraction as an integer, if possible
        if(in>>frac.num)
        {
            if(in.peek() == '/')
            {
                if (neg)
                    frac.num *= -1;
                in >> junk >> frac.denom;
                if(frac.denom == 0)
                    throw DivByZero;
                frac.reduce();
            }
            if (in.peek() == '.') // Example "0.5"
            {
                double temp;
                in >> temp;
                temp = temp + frac.num;
                if (neg)
                    temp *= -1;
                fraction a(temp);
                frac = a;
                frac.reduce();

            }
        }
        // If possible fraction can't be put into integer, it is likely a decimal
        else  // Example ".5"
        {
            in.clear();
            if ((in.peek() == '.'))
            {
                double temp;
                in >> temp;
                if (neg)
                    temp *= -1;
                fraction a(temp);
                frac = a;
                frac.reduce();
            }
        }
    }
    return in;
}

fraction operator+(const fraction &x,const fraction &y)
{
    fraction result;
    int num = x.num * y.denom + y.num  * x.denom,
        denom = x.denom * y.denom;
    result.setValue(num,denom);
    return result;
}

fraction operator-(const fraction &x,const fraction &y)
{
    fraction result;
    int num = x.num * y.denom - y.num  * x.denom,
        denom = x.denom * y.denom;
    result.setValue(num,denom);
    return result;
}

fraction operator*(const fraction &x,const fraction &y)
{
    fraction result;
    int num = x.num * y.num,
        denom = x.denom * y.denom;
    result.setValue(num,denom);
    return result;
}

fraction operator/(const fraction &x,const fraction &y)
{
    fraction result;
    int num = x.num * y.denom,
        denom = x.denom * y.num;
    result.setValue(num,denom);
    return result;
}

fraction operator^(const fraction &x,const fraction &y)
{
    double temp1 = pow(pow(x.num, y.num),1./y.denom),
            temp2 = pow(pow(x.denom, y.num),1./y.denom);
    return temp1/temp2;
}

bool operator==(const fraction &x,const fraction &y)
{
    return x.num * y.denom == y.num * x.denom;
}

bool operator>=(const fraction &x,const fraction &y)
{
    return x.num * y.denom >= y.num * x.denom;
}

bool operator<=(const fraction &x,const fraction &y)
{
    return x.num * y.denom <= y.num * x.denom;
}

bool operator!=(const fraction &x,const fraction &y)
{
    return x.num * y.denom != y.num * x.denom;
}

bool operator<(const fraction &x,const fraction &y)
{
    return x.num * y.denom < y.num * x.denom;
}

bool operator>(const fraction &x,const fraction &y)
{
    return x.num * y.denom > y.num * x.denom;
}
