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
std::array<int, 2> find_roots(int B, int C)
{
    assert( (B != 0) & (C != 0) ); // make sure both are positive 
    
    int left{}; 
    int right{};
    int sign_change = B > 0 ? 1 : -1;  
    if (C > 0) // c is positive, adding inward bounded by the halfway point 
    {
        int pos_B = sign_change * B; 
        int halfway = ((pos_B) % 2) == 0 ? pos_B / 2 : (pos_B - 1) / 2; // getting halfway point 
        for ( left = 1; left <= halfway; ++left )
        {
            right = halfway - left;
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