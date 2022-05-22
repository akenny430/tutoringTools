#include "Rational.hpp"
#include "numberTheory.hpp" /* euclid_gcd, lcm */ 

#include <iostream>
#include <array> 



Rational::Rational(int num, int den)
    : m_num{ num }, m_den{ den }
{
    assert(den != 0); 
}

int Rational::get_num()
{
    return m_num; 
}

int Rational::get_den()
{
    return m_den; 
}

std::array<int, 2> aux_simplify(int num, int den)
{
    if (den < 0) // if denominator is negative, multiply top and bottom by -1 
    {
        num *= -1; 
        den *= -1; 
    }
    int gcd = euclid_gcd(num, den); // finding gcd 
    if (gcd == 1) // if gcd is 1, don't even bother dividing 
        return std::array<int, 2> { num, den };
    num /= gcd; 
    den /= gcd;
    return std::array<int, 2> { num, den };
}

Rational& Rational::simplify()
{
    std::array<int, 2> new_vals = aux_simplify(m_num, m_den); 
    m_num = new_vals[0]; 
    m_den = new_vals[1];
    return *this; 
}

Rational Rational::give_simplify() const 
{
    std::array<int, 2> new_vals = aux_simplify(m_num, m_den); 
    return Rational{ new_vals[0], new_vals[1] }; 
}

void Rational::junk_print()
{
    std::cout << m_num << '/' << m_den << '\n';
}

void Rational::print_individual()
{
    std::cout << "Numerator = " << m_num << ", Denominator = " << m_den << '\n'; 
}

/* constfun */
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
    Rational z = y / x; 
    return Rational{ z.m_den, z.m_num }; 
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

// std::ostream& operator>>(std::ostream& out, const Rational& x)
// {

// }

bool operator==(const Rational& x, const Rational& y)
{
    Rational z = x.give_simplify(); 
    Rational w = y.give_simplify(); 
    return ( (z.m_num == w.m_num) && ( z.m_den == w.m_den ) ); 
}

bool operator==(const Rational& x, int y)
{
    return ( (x.m_num == y) && (x.m_den == 1) ); 
}

bool operator==(int x, const Rational& y)
{
    return y == x; 
}

bool operator!=(const Rational& x, const Rational& y)
{
    return !(x == y); 
}

bool operator!=(const Rational& x, int y)
{
    return !(x == y); 
}

bool operator!=(int x, const Rational& y)
{
    return !(x == y); 
}




// int main()
// {
//     std::cout << "Declaring variables:\n"; 
//     Rational x {5, 7}; 
//     Rational y {2, 3}; 
//     std::cout << "x = " << x << ", y = " << y << '\n';

//     std::cout << "Addition and subtraction\n"; 
//     std::cout << "x + y = " << x + y << '\n'; 
//     std::cout << "x - y = " << x - y << '\n'; 
//     std::cout << "x - 1 = " << x - 1 << '\n'; 

//     std::cout << "Multiplication and division\n"; 
//     std::cout << "x * y = " << x * y << '\n'; 
//     std::cout << "x / y = " << x / y << '\n'; 
//     std::cout << "4 / y = " << 4 / y << '\n'; 

//     return 0; 
// }