#pragma once 

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

    /* simplifying the rational expression if possible */
    // void simplify();
    Rational& simplify();


    void junk_print(); 

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
}; 