/**
  * @author Koll Klienstuber, Partner Hannah Madland
  * @brief Assignment 5
  */

#include "MyComplex.h"
#include <string>
#include<cmath>
#include<sstream>

MyComplex::MyComplex(){
    real = 0.0;
    imaginary = 0.0;
}



MyComplex::MyComplex(double a)
{
    this->real = a;
    this->imaginary = 0.0;
}


MyComplex::MyComplex(double a, double b)
{
    this->real = a;
    this->imaginary = b;
}

double MyComplex:: getRealPart() const
{
    return real;
}

double MyComplex:: getComplexPart() const
{
    return imaginary;

}

string MyComplex::toString()
{
    return to_string(real) + "/" + to_string(imaginary);
}



//--------------------Member Operators------------------------------

//Define functions for arithmetic member operators

MyComplex operator+(const MyComplex& firstC, const MyComplex& secondC)
{
    //Implemented as a friend, so it has private access
    double a = firstC.real + secondC.real;
    double b = firstC.imaginary + secondC.imaginary;
    return MyComplex (a,b);
}

MyComplex operator-(const MyComplex& firstC, const MyComplex& secondC)
{
    //Implemented as a friend, so it has private access
    double a = firstC.real - secondC.real;
    double b = firstC.imaginary - secondC.imaginary;
    return MyComplex (a,b);
}



MyComplex operator*(const MyComplex& firstC, const MyComplex& secondC)
{
     double a = ((firstC.real)* (secondC.real)) - ((firstC.imaginary)* (secondC.imaginary));
     double  b = ((firstC.real)*(secondC.imaginary)+ (secondC.real)* firstC.imaginary);
     return MyComplex (a, b);
}
MyComplex operator/(const MyComplex& firstC, const MyComplex& secondC)
{
double a =(((firstC.real)*(secondC.real))+((firstC.imaginary)*(secondC.imaginary)))/(pow(secondC.real,2)+ pow(secondC.imaginary,2));
double b =(((secondC.real)*(firstC.imaginary))-((firstC.real)*(secondC.imaginary)))/(pow(secondC.real,2)+ pow(secondC.imaginary,2));
return MyComplex(a,b);
}

bool MyComplex::operator==(const MyComplex& secondC) const
{
    double val1 = real * secondC.imaginary;
    double val2 = secondC.real * imaginary;
    return (val1 == val2);
}

bool MyComplex::operator!=(const MyComplex& secondC) const
{
    double val1 = real * secondC.imaginary;
    double val2 = secondC.real * imaginary;
    return (val1 != val2);
}


// Define function operators for shorthand operators

MyComplex& MyComplex::operator+=(const MyComplex& secondC)
{
    double a = real + secondC.getRealPart();
    double b = imaginary + secondC.getComplexPart();
    real = a;
    imaginary = b;
    return *this;
}



MyComplex& MyComplex::operator-=(const MyComplex& secondC)
{
    double a = real - secondC.getRealPart();
    double b = imaginary - secondC.getComplexPart();
    real = a;
    imaginary = b;
    return *this;
}

MyComplex& MyComplex::operator*=(const MyComplex& secondC)
{
   double a = imaginary * secondC.getRealPart() + real * secondC.getComplexPart();
   double b = real * secondC.getComplexPart() + imaginary * secondC.getRealPart() ;
    real = a;
    imaginary = b;
    return *this;
}



MyComplex& MyComplex::operator/=(const MyComplex& secondC)
{
    double a =(((real)*(secondC.real))+((imaginary)*(secondC.imaginary)))/(pow(secondC.real,2)+ pow(secondC.imaginary,2));
    double b =(((secondC.real)*(imaginary))-((real)*(secondC.imaginary)))/(pow(secondC.real,2)+ pow(secondC.imaginary,2));
    real = a;
    imaginary = b;
    return *this;
}



// Define function operators for prefix ++ and --

MyComplex& MyComplex::operator--()
{
    real -= 1;
    return *this;
}

MyComplex& MyComplex::operator++()
{
    real += 1;
    return *this;
}


MyComplex MyComplex::operator++(int) //don't need real name for dummy param
{
        MyComplex temp(real, imaginary);
        real += 1;

        return temp;
}



MyComplex MyComplex::operator--(int) //don't need real name for dummy param
{
    MyComplex temp (real, imaginary);
    real -= 1;
    return temp;
}





MyComplex MyComplex::operator+() const
{
   //return copy of self
    return *this;
}


MyComplex MyComplex::operator-() const
{
    return MyComplex(-real, -imaginary);
}


double& MyComplex::operator[](int index)
{
    if (index == 0)
        return real;
    else if (index == 1)
        return imaginary;
    else
    {
        cout << "No can do..." << endl;
        exit(0);
    }
}

ostream& operator<<(ostream& stream, const MyComplex& output){
       if (output.imaginary < 0){
           stream << output.real << " - " << output.imaginary * -1 << "i";
}
       else

           stream << output.real << " + " << output.imaginary << "i";
       return stream;

}

istream& operator >> (istream& stream, MyComplex& input){
    stream >> input.real;
    char c;
    stream >> c;
    stream >> input.imaginary;
    char c2;
    stream >> c2;


    if(c2 != 'i' || !stream) {
        cout << "Input Failure" << endl;
        exit(0);
    }
    if(c == '-'){
        input.imaginary *= -1;
    }
    return stream;
}


