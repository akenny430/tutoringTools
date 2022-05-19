#include "Rational.hpp"
#include "numberTheory.hpp" /* euclid_gcd */ 

#include <iostream>



Rational::Rational(int num, int den)
    : m_num{ num }, m_den{ den }
{
    assert(den != 0); 
}

Rational& Rational::simplify()
{
    /* template this to possibly account for other data types? */
    int gcd = euclid_gcd(m_num, m_den); 
    m_num = m_num / gcd; 
    m_den = m_den / gcd; 
    return *this; 
}

void Rational::junk_print()
{
    std::cout << m_num << '/' << m_den << '\n';
}

// Rational Rational::m_get_reciprocal()
// {
//     // int temp = m_num; 
//     // m_num = m_den; 
//     // m_den = temp; 
//     // return *this; 
//     return Rational{ m_den, m_num }; 
// }



Rational operator*(const Rational& x, const Rational& y)
{
    return Rational{ x.m_num * y.m_num, x.m_den * y.m_den }.simplify(); 
}

Rational operator/(const Rational& x, const Rational& y)
{
    // Rational z = y.m_get_reciprocal(); 
    // return x * z; 
    return Rational{ x.m_num * y.m_num, x.m_den * y.m_den }.simplify(); 
}



int main()
{
    Rational a {}; 
    a.junk_print(); 
    Rational b {2}; 
    b.junk_print(); 
    Rational c {5, 7}; 
    c.junk_print(); 

    Rational d {3, 6}; 
    d.junk_print(); 
    d.simplify(); 
    d.junk_print();

    Rational e = c * d; 
    e.junk_print(); 

    Rational f = b / c; 
    f.junk_print(); 

    return 0; 
}