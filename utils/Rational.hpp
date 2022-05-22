#pragma once 

#include <iostream>

class Rational
{
    // using number_type = int; /* maybe want to make numbers as long int or something else  */
private: 
    int m_num {}; 
    int m_den {}; 
    // Rational m_get_reciprocal(); 
public: 
    /* default constructor */
    Rational(int num = 1, int den = 1);

    /* getting numerator and denominator */
    int get_num(); 
    int get_den(); 

    /* simplifying the rational expression if possible */
    // void simplify();
    Rational& simplify();
    Rational give_simplify() const;


    void junk_print(); 
    void print_individual();

    /* multiplication */
    friend Rational operator*(const Rational& x, const Rational& y);
    friend Rational operator*(const Rational& x, int y); 
    friend Rational operator*(int x, const Rational& y); 

    /* division */
    friend Rational operator/(const Rational& x, const Rational& y);
    friend Rational operator/(const Rational& x, int y); 
    friend Rational operator/(int x, const Rational& y); 

    /* addition */
    friend Rational operator+(const Rational& x, const Rational& y); 
    friend Rational operator+(const Rational& x, int y); 
    friend Rational operator+(int x, const Rational& y); 

    /* subtraction */
    friend Rational operator-(const Rational& x, const Rational& y); 
    friend Rational operator-(const Rational& x, int y); 
    friend Rational operator-(int x, const Rational& y); 

    /* iostream */
    friend std::ostream& operator<<(std::ostream& out, const Rational& x);
    // friend std::ostream& operator>>(std::ostream& out, const Rational& x);

    /* comparison == */
    friend bool operator==(const Rational& x, const Rational& y); 
    friend bool operator==(const Rational& x, int y); 
    friend bool operator==(int x, const Rational& y); 

    /* comparison != */
    friend bool operator!=(const Rational& x, const Rational& y); 
    friend bool operator!=(const Rational& x, int y); 
    friend bool operator!=(int x, const Rational& y); 
}; 