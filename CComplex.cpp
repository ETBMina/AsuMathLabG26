#include "CComplex.h"
#include <string>
#include <math.h>
#include <stdio.h>

CComplex::CComplex()
{
    R = I = 0.0;
}

CComplex::~CComplex()
{
    //dtor
}

CComplex::CComplex(double R, double I)
{
    this->R = R; this->I = I;
}

CComplex::CComplex(const CComplex& C)
{
    R = C.R; I = C.I;
}

string CComplex::getString()
{
    char text[100];
    if(I==0)sprintf(text, "%g", R);
    else if(R==0)sprintf(text, "%g * i", I);
    else if(I>0)sprintf(text, "%g + %g * i", R, I);
    else if(I<0)sprintf(text, "%g - %g * i", R, -I);
    return string(text);
}

double CComplex::magnitude()
{
    return sqrt(R*R+I*I);
}
double CComplex::angle()
{
    return atan2(I, R);
}

void CComplex::negative()
{
    R*=-1; I*=-1;
}

double CComplex::real()
{
    return R;
}

double CComplex::imaginary()
{
    return I;
}

void CComplex::add(CComplex& C)
{
    R += C.R;I += C.I;
}

void CComplex::sub(CComplex& C)
{
    R -= C.R;I -= C.I;
}

CComplex CComplex::operator=(const CComplex& C)
{
    R = C.R; I = C.I;
    return *this;
}
CComplex CComplex::operator=(double D)
{
    R = D;I = 0;
    return *this;
}
void CComplex::operator+=(CComplex& C)
{
    add(C);
}
void CComplex::operator+=(double D)
{
    R += D;
}
CComplex CComplex::operator+(CComplex& C)
{
    CComplex X=*this;
    X+=C;
    return X;
}
CComplex CComplex::operator+(double D)
{
    CComplex X=*this;
    X+=D;
    return X;
}

void CComplex::operator-=(CComplex& C)
{
    sub(C);
}
void CComplex::operator-=(double D)
{
    R -= D;
}
CComplex CComplex::operator-(CComplex& C)
{
    CComplex X=*this;
    X-=C;
    return X;
}
CComplex CComplex::operator-(double D)
{
    CComplex X=*this;
    X-=D;
    return X;
}

CComplex CComplex::operator-()
{
    return CComplex(-R, -I);
}
CComplex::operator const string()
{
    return getString();
}
/*istream& operator >> (istream& is, CComplex& C)
{
    is>>C.R;
    is>>C.I;
    return is;
}*/
ostream& operator << (ostream& os, CComplex& C)
{
    os<<C.getString();return os;
}
CComplex CComplex::operator++()
{
    R++;
    return *this;
}
CComplex CComplex::operator++(int)
{
    CComplex C = *this;
    R+=1;
    return C;
}
