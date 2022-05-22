#pragma once 

#include "../utils/Rational.hpp" /* Rational class */ 
#include <array> 

// std::array<int, 2> find_numbers(Rational x, Rational y);

// std::array<int, 2> get_roots(std::array<int, 2> coefs); 
std::array<Rational, 2> find_roots(Rational a, Rational b, Rational c); 