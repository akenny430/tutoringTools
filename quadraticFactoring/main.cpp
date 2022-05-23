#include "quadf.hpp" 
#include "input.hpp" /* turn_from_string */
#include "../utils/Rational.hpp" /* Rational */

#include <iostream> 
#include <array>



int main()
{
    std::cout << "Enter three coefficients, separated by space: \n";
    std::string in_a; 
    std::string in_b; 
    std::string in_c; 
    Rational a{}; 
    Rational b{}; 
    Rational c{};

    while(1) 
    {
        std::cin >> in_a; 
        if (in_a[0] == '0') 
            break; 
        std::cin >> in_b >> in_c; 

        a = turn_from_string(in_a); 
        b = turn_from_string(in_b); 
        c = turn_from_string(in_c); 

        std::array<Rational, 2> roots = find_roots(a, b, c); 

        std::cout << "a = " << a << ", roots at x = " << roots[0] << " and x = " << roots[1] << '\n'; 
    }
    
     
    // read in inputs from user once programs starts 
    // starting from a and b and c 
    // then find roots 
    // then print out roots 

    return 0; 
}