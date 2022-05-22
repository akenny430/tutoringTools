#include "../utils/Rational.hpp"

#include <iostream>
#include <string>



Rational turn_from_string(std::string number_str)
{
    int where{}; 
    if ((where = number_str.find('/')) != std::string::npos) // / is in string, so split and create numerator and denominator 
    {
        return Rational{ 
            std::stoi( number_str.substr(0, where) ), 
            std::stoi( number_str.substr(where + 1, number_str.size() - where - 1) )
        }; 
    }
    else 
    {
        return Rational{ std::stoi(number_str) }; 
    }
}