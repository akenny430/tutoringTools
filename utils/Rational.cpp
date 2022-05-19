#include "Rational.hpp"
#include "numberTheory.hpp" /* euclid_gcd */ 

#include <iostream>



Rational::Rational(int num, int den)
    : m_num {num}, m_den {den}
{
    assert(den != 0); 
    // m_num = num; 
    // m_den = den; 
}

void Rational::simplify(Rational x)
{
    /* template this to possibly account for other data types? */
    int gcd = euclid_gcd(x.m_num, x.m_den); 
    m_num = m_num / gcd; 
    m_den = m_den / gcd; 
}

void Rational::junk_print()
{
    std::cout << m_num << '/' << m_den << '\n';
}

int main()
{
    Rational a {}; 
    a.junk_print(); 
    Rational b {2}; 
    b.junk_print(); 
    Rational c {5, 7}; 
    c.junk_print(); 

    return 0; 
}