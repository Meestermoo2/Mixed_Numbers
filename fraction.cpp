#include "fraction.h"

fraction::fraction()
{
    num = 0;
    denom = 1;
}

fraction::fraction(int n, int d)
{
   setValue(n,d);
}

fraction::~fraction()
{
    num = denom = 0;
}

fraction::fraction(const fraction &frac)
{
    num = frac.num;
    denom = frac.denom;
}

fraction::fraction(const double &other)
{
    std::string wholePart, fractionPart;
    std::stringstream ss;
    ss<<other;
    getline(ss,wholePart,'.');
    getline(ss,fractionPart);
    int numDigits = fractionPart.size();
    denom = makeDenom(numDigits, allDecimalsTheSame(fractionPart));
    num = denom * abs(std::stoi(wholePart)) + abs(std::stoi(fractionPart));
    reduce();
    num *= std::stoi(wholePart)/abs(std::stoi(wholePart));
}

bool fraction::allDecimalsTheSame(const std::string &fracPart)
{
    if(fracPart.size()<3)
            return false;//credit to yuner
    bool yes = true;
    for(int i = 1; yes && i < fracPart.size(); ++i)
        yes = (fracPart[0] == fracPart[i]);
    return yes;
}

int fraction::makeDenom(int digits, bool same)
{
    std::string result("1");
    for(int i = 0; i < digits; ++i)
        result += "0";
    return std::stoi(result) - (int)same * 1;
}

fraction& fraction::operator=(const fraction &frac)
{
    if(this != &frac)
    {
        num = frac.num;
        denom = frac.denom;
    }
    return *this;
}

fraction& fraction::operator+=(const fraction &other)
{
    *this = *this + other;
    return *this;
}

fraction& fraction::operator-=(const fraction &other)
{
    *this = *this - other;
    return *this;
}

fraction& fraction::operator*=(const fraction &other)
{
    *this = *this * other;
    return *this;
}

fraction& fraction::operator/=(const fraction &other)
{
    *this = *this / other;
    return *this;
}


int fraction::getNum() const //accessor function for numerator
{
    return num;
}

int fraction::getDenom() const//accessor function for denominator
{
    return denom;
}

void fraction::setValue(int n, int d) //mutator function
{
    num = n;
    denom = d;
    reduce();
}

void fraction::display()
{
    std::cout<<" "<<num;
    if(denom != 1)
       std::cout<<"/"<<denom<<" ";
}


void fraction::getInput()
{
    char junk;
    std::cin>>num>>junk>>denom;
    reduce();
}


void fraction::reduce()
{
    std::cout<<"num = "<<num<<" denom = "<<denom<<std::endl;
    bool neg = num < 0 || denom < 0,
         both = num < 0 && denom < 0;
    int divisor = gcd(abs(num), abs(denom));
    num = abs(num) / divisor;
    denom = abs(denom) / divisor;
    if(!both) //Asking is both == false
        if(neg)
            num *= -1;
    std::cout<<"num = "<<num<<" denom = "<<denom<<std::endl;
}

int fraction::gcd(int p, int q)
{
   return !q ? p : gcd(q, p%q);  //!q is the same as asking q == 0;
}


