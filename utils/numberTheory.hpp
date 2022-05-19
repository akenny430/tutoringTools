// #ifndef PRIME_H 
// #define PRIME_H 
#pragma once 

/**
 * Implements Miller-Rabin prime tester with 100 random iterations
 * 
 * @param n: number to test for prime
 * 
 * @returns: 1 indicating number is prime, 0 if number is not prime
 */
int is_prime(int n);



/**
 * Finds GCD of two positive numbers using Euclid's algorithm 
 * 
 * @param x: first number 
 * @param y: second number 
 * 
 * @returns: GCD between x and y
*/
int euclid_gcd(int x, int y); 

/**
 * Finds LCM of two positive numbers 
 * 
 * @param x: first number 
 * @param y: second number 
 * 
 * @returns: GCD between x and y
*/
int lcm(int x, int y); 

// #endif
