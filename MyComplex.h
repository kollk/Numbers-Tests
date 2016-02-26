/**
  * @author Koll Klienstuber, Partner Hannah Madland
  * @brief Assignment 5
  */
#ifndef MyComplex_H
#define MyComplex_H
#include <string>
#include <iostream>
using namespace std;

class MyComplex
{
public:



    /**
     * @brief MyComplex 0 argument constructor real and imaginary numbers are set to 0
     */
    MyComplex();

    /**
     * @brief MyComplex 1 argument constructor argument is value of real, imaginary is set to 0
     * @param a the value of the real number
     */
    MyComplex(double a);

    /**
     * @brief MyComplex 2 arument constructor takes in both real and imaginary values
     * @param a value of real number
     * @param b value of imaginary number
     */
    MyComplex(double a, double b);

    /**
     * @brief getRealPart returns real part of complex number
     * @return real part of complex number
     */
    double getRealPart() const;

    /**
     * @brief getComplexPart returns imaginary part of complex number
     * @return returns imaginary part of complex number
     */
    double getComplexPart() const;

    /**
     * @brief toString returns a string with the representation of complex number.
     * @return complex number string
     */
    string toString();


    /**
     * @brief operator [] accesses the real or imaginary part of the complex number
     * @param index values 0 or 1
     * @return real or imaginary part based off index
     */
    double& operator[](int index);


    /**
     * @brief operator + adds two complex numbers
     * @param firstComplex first complex number
     * @param secondComplex second complex number
     * @return new complex number
     */
    friend MyComplex operator+(const MyComplex& firstComplex, const MyComplex& secondComplex);


    /**
     * @brief operator - subtracts one complex number from another
     * @param firstComplex the first complex number
     * @param secondComplex the second complex number to be subtracted
     * @return new complex number
     */
    friend MyComplex operator-(const MyComplex& firstComplex, const MyComplex& secondComplex);


    /**
     * @brief operator * multiplies two complex numbers
     * @param firstComplex first complex number
     * @param secondComplex second complex number
     * @return new complex number
     */
    friend MyComplex operator*(const MyComplex& firstComplex, const MyComplex& secondComplex);
    friend MyComplex operator/(const MyComplex& firstComplex, const MyComplex& secondComplex);


    /**
     * @brief operator == checks if two complex numbers are equal
     * @param secondComplex complex number being compared
     * @return result
     */
    bool operator==(const MyComplex& secondComplex) const;


    /**
     * @brief operator != checks if two complex numbers are not equal
     * @param secondComplex complex number being compared
     * @return result
     */
    bool operator!=(const MyComplex& secondComplex) const;

    /**
     * @brief operator -= subtracts a specified complex number from another
     * @param secondComplex the second complex number to be subtracted
     * @return new complex number
     */
    MyComplex& operator-=(const MyComplex& secondComplex);

    /**
     * @brief operator += adds a specified complex number to another
     * @param secondComplex the second complex number
     * @return new complex number
     */
    MyComplex& operator+=(const MyComplex& secondComplex);


    /**
     * @brief operator *= multiplies a complex number by another specified one
     * @param secondComplex the number to be multiplied by
     * @return new complex number
     */
    MyComplex& operator*=(const MyComplex& secondComplex);


    /**
     * @brief operator /= divides a complex number by another specified one
     * @param secondComplex the number divided by
     * @return new complex number
     */
    MyComplex& operator/=(const MyComplex& secondComplex);



    /**
     * @brief operator ++ increases by 1 and then evaluates to the new value
     * @return new value
     */
    MyComplex& operator++();

    /**
     * @brief operator -- decreases by 1 and then evaluates to the new value
     * @return new value
     */
    MyComplex& operator--();



    /**
     * @brief operator ++ increases by 1 to the variable but evaluates to the old value
     * @param a dummy variable
     * @return old value
     */
    MyComplex operator++(int a);

    /**
     * @brief operator -- decreases by 1 to the variable but evaluates to the old value
     * @param a dummy variable
     * @return old value
     */
    MyComplex operator--(int a);



    /**
     * @brief operator + operates + on the operand turning it positive
     * @return positive operand
     */
    MyComplex operator+() const;

    /**
     * @brief operator - operates - turning it negative
     * @return negative operand
     */
    MyComplex operator-() const;


    /**
     * @brief operator << reads in a complex number
     * @param stream ostream reference
     * @param output of the complex number
     * @return stream
     */
    friend  ostream& operator<<(ostream& stream, const MyComplex& output);

    /**
     * @brief operator >> outputs a complex number
     * @param stream instream reference
     * @param input of the complex number
     * @return stream
     */
    friend istream& operator>>(istream& stream, MyComplex& input);

private:
    double real;
    double imaginary;
};

#endif
