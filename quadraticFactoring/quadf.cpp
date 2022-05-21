#include "../utils/Rational.hpp" /* Rational class */
#include "../utils/numberTheory.hpp" /* lcm */
#include <array>

/* given two Rational, return array of numerators to use to find roots */
std::array<int, 3> find_numbers(Rational a, Rational b, Rational c)
{
    // dividing out by a 
    Rational x = b / a; 
    Rational y = c / a; 
    // final denominator will be lcm of denominators of x and y 
    int final_den = lcm(x.get_den(), y.get_den()); 
    // getting augmented B and C from this 
    int B = x.get_num() * (final_den / x.get_den()); 
    int C = y.get_num() * (final_den / y.get_den()) * final_den; 
    // returning final denominator, B, and C 
    return std::array<int, 3> { final_den, B, C }; 
}



/* given nonzero B and C, find two numbers that satisfy system if they exist */
std::array<int, 2> solve_system(int B, int C)
{
    assert( (B != 0) && (C != 0) ); // make sure both are positive 
    
    int left{}; 
    int right{};
    int sign_change = B > 0 ? 1 : -1;  
    if (C > 0) // c is positive, adding inward bounded by the halfway point 
    {
        int pos_B = sign_change * B; 
        int halfway = ((pos_B) % 2) == 0 ? pos_B / 2 : (pos_B - 1) / 2; // getting halfway point 
        for ( left = 1; left <= halfway; ++left )
        {
            right = pos_B - left;
            if (left * right == C)
                return std::array<int, 2> { sign_change * left, sign_change * right }; 
        }
    }
    else // c is negative, adding outward bounded by any multiplication greater than C 
    {
        left = B + sign_change; 
        right = -sign_change; 
        int prod{}; 
        while( (prod = left * right) >= C ) /* how would we catch errors for this? */
        {
            if (prod == C)
                return std::array<int, 2> { left, right };
            left += sign_change; 
            right -= sign_change; 
        }
    }
    // if no possible combo is found 
    return std::array<int, 2> { 0, 0 };   
}



/* given three coefficients as rational numbers, find the two numbers that satisfy system */
std::array<Rational, 2> find_roots(Rational a, Rational b, Rational c)
{
    /* for now, assume B != 0, but can still deal with case of C == 0 */
    // assert((a.get_num() != 0) && (b.get_num() != 0)); 
    assert((a != 0) && (b != 0)); 
    if (c.get_num() == 0)
    {
        return std::array<Rational, 2> { Rational{ 0 }, b / a }; 
    }
    std::array<int, 3> params = find_numbers(a, b, c); 
    std::array<int, 2> sys_sol = solve_system(params[1], params[2]); 
    // returning both solutions as Rationals 
    return std::array<Rational, 2> { 
        Rational{ sys_sol[0], params[0] }.simplify(), Rational{ sys_sol[1], params[0] }.simplify()
    }; 
}



int main()
{
    Rational a {}; 
    Rational b { 1 }; 
    Rational c { -90 }; 
    std::cout << "Coefficients are: a = " << a << ", b = " << b << ", and c = " << c << '\n'; 

    std::array<Rational, 2> solutions = find_roots(a, b, c); 
    for ( auto sol : solutions )
    {
        std::cout << "root = " << sol << '\n'; 
    }

    return 0; 
}