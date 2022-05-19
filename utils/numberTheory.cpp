#include "numberTheory.hpp"
// #include <cstdlib> // for random numbers 
#include <random> /* Better random numbers */



// auxiliary function for taking the mod of an exponential number, a^c mod n
int mod_exponentiation(int a, unsigned b, int n)
{
    int c = 0; 
    int d = 1;
    for (unsigned k = 1 << 31; k > 0; k = k / 2)
    {
        c *= 2;
        d = ( d * d ) % n;
        if ( b & k )
        {
            c += 1;
            d = ( d * a ) % n;
        }
    }
    return d; 
}



// auxiliary witness function, checks "is this number composite?" 
// returns 1 if number is composite, otherwise returns 0 
int witness(int a, int n)
{
    // checking to see if n is even (if so, then it is not prime)
    if (n % 2 == 0)
    {
        return 0;
    }
    
    // figuring out what t and u have to be from n
    int m = n - 1;
    int t = 0;
    while (m % 2 == 0) 
    {
        ++t; 
        m /= 2;
    }
    unsigned u = (unsigned)m;

    int x0 = mod_exponentiation(a, u, n); 
    int x1; 
    for (int i = 0; i < t; ++i) 
    { 
        x1 = (x0 * x0) % n; 
        if ( x1 == 1 && x0 != 1 && x0 != n - 1 )
        {
            return 1;
        }
    x0 = x1; 
    } 
    if ( x1 != 1 )
    {
        return 1;
    }
    return 0;
}



// driver function to test if a number n is prime 
// returns 1 if the number is prime, otherwise returns 0
int miller_rabin(int n, int s)
{
    // checking to see if the number is even or less than 2 
    if (n % 2 == 0 || n < 2) 
    { 
        return 0;
    } 

    /* making random number generator to use  */
    std::random_device dev;  
    std::mt19937 rng(dev());
    std::uniform_int_distribution< std::mt19937::result_type > witness_dist(1, n - 1); 

    // looping through the various iterations 
    for (int k = 0; k < s; ++k)
    {

        /* generates random number between 1 and n - 1 */
        // int a = (rand() % ( n - 1 )) + 1;
        int a = witness_dist(rng); 

        /* if the witness says it is composite, return 0, otherwise return 1 */
        if (witness(a, n) == 1)
        {
           return 0;
        } 
    }
    return 1; 
}



// specifies prime check with 100 random iterations 
int is_prime(int n)
{
    return miller_rabin(n, 100);
}



int euclid_gcd(int x, int y)
{
    /* finds the gcd of x and y using Euclid's algorithm */
    // return 0; 
    int r = x % y; 
    return r == 0 ? y : euclid_gcd(y, r); 
}