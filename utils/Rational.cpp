#include "Rational.hpp"
#include "numberTheory.hpp" /* euclid_gcd, lcm */ 

#include <iostream>



Rational::Rational(int num, int den)
    : m_num{ num }, m_den{ den }
{
    assert(den != 0); 
}

Rational& Rational::simplify()
{
    /* template this to possibly account for other data types? */
    if (m_den < 0) // if denominator is negative, multiply top and bottom by -1 
    {
        m_num *= -1; 
        m_den *= -1; 
    }
    int gcd = euclid_gcd(m_num, m_den); // finding gcd 
    if (gcd == 1) // if gcd is 1, don't even bother dividing 
        return *this; 
    m_num = m_num / gcd; 
    m_den = m_den / gcd; 
    return *this; 
}

void Rational::junk_print()
{
    std::cout << m_num << '/' << m_den << '\n';
}

void Rational::print_individual()
{
    std::cout << "Numerator = " << m_num << ", Denominator = " << m_den << '\n'; 
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
    return y * x; 
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
    return y / x; 
}

Rational operator+(const Rational& x, const Rational& y)
{
    int the_lcm = lcm(x.m_den, y.m_den); 
    int l_num = x.m_num * (the_lcm / x.m_den); 
    int r_num = y.m_num * (the_lcm / y.m_den); 
    return Rational{ l_num + r_num, the_lcm }.simplify(); 
}
Rational operator+(const Rational& x, int y)
{
    return (x + Rational{ y * x.m_den, x.m_den }).simplify(); 
}
Rational operator+(int x, const Rational& y)
{
    return y + x; 
}

Rational operator-(const Rational& x, const Rational& y)
{
    return x + ( -1 * y ); 
}
Rational operator-(const Rational& x, int y)
{
    return x + (-y); 
}
/* TODO: have to make negative sign go into numerator, something to do with lcm?  */
Rational operator-(int x, const Rational& y)
{
    // return x + (-1 * y); 
    return -1 * ( y - x ); 
}

std::ostream& operator<<(std::ostream& out, const Rational& x)
{
    if (x.m_den == 1)
    {
        out << x.m_num; 
        return out; 
    }
    out << x.m_num << '/' << x.m_den; 
    return out; 
}


int main()
{
    std::cout << "Declaring variables:\n"; 
    Rational x {5, 7}; 
    Rational y {2, 3}; 
    std::cout << "x = " << x << ", y = " << y << '\n';

    std::cout << "Addition and subtraction\n"; 
    std::cout << "x + y = " << x + y << '\n'; 
    std::cout << "x - y = " << x - y << '\n'; 
    std::cout << "x - 1 = " << x - 1 << '\n'; 

    std::cout << "Multiplication and division\n"; 
    std::cout << "x * y = " << x * y << '\n'; 
    std::cout << "x / y = " << x / y << '\n'; 
    std::cout << "4 / y = " << 4 / y << '\n'; 

    return 0; 
}