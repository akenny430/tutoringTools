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
    if (gcd == 1)
        return *this; 
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
Rational operator*(const Rational& x, int y)
{
    return (x * Rational{ y }).simplify(); 
}
Rational operator*(int x, const Rational& y)
{
    return (Rational{ x } * y).simplify(); 
}

Rational operator/(const Rational& x, const Rational& y)
{
    // Rational z = y.m_get_reciprocal(); 
    // return x * z; 
    return Rational{ x.m_num * y.m_den, x.m_den * y.m_num }.simplify(); 
}
Rational operator/(const Rational& x, int y)
{
    return (x / Rational{ y }).simplify(); 
}
Rational operator/(int x, const Rational& y)
{
    return (Rational{ x } / y).simplify(); 
}



int main()
{
    Rational a {}; 
    Rational b {2}; 
    Rational c {5, 7}; 
    Rational d {3, 6}; 
    d.junk_print(); 
    d.simplify(); 
    d.junk_print();

    std::cout << "Multiplication\n"; 
    Rational e = c * d; 
    Rational e2 = e * 5; 
    Rational e3 = e2 * 5; 
    e.junk_print(); 
    e2.junk_print(); 
    e3.junk_print(); 

    std::cout << "Division\n"; 
    Rational f = b / c; 
    Rational f2 = f / 3; 
    Rational f3 = 2 / f2; 
    f.junk_print(); 
    f2.junk_print(); 
    f3.junk_print(); 

    return 0; 
}