#include <stdexcept>
#include "Fraction.hpp"

using namespace std;
using namespace ariel;

// This function removes the greatest common divisor (gcd) from the fraction
void ariel::Fraction::remove_gcd()
{
    int gcd = __gcd(numerator, denominator);

    numerator /= gcd;
    denominator /= gcd;

    if (denominator < 0 && numerator > 0)
    {
        numerator = -1 * numerator;
        denominator = -1 * denominator;
    }
}

// Constructor that takes two integer arguments, representing the numerator and denominator of the fraction
ariel::Fraction::Fraction(int x, int y) : numerator(x), denominator(y)
{
    // If the denominator is zero, throw an exception
    if (y == 0)
    {
        throw std::invalid_argument(" you divide by zero !!! ");
    }
    else
    {
        // Check if the numerator and denominator are equal to the global maximum or minimum values
        // If they are, set the numerator and denominator to 1 or -1 accordingly
        if ((x == global_maximum && y == global_maximum) || (x == global_minimum && y == global_minimum))
        {
            numerator = 1;
            denominator = 1;
        }
        else if ((x == global_maximum && y == global_minimum) || (x == global_minimum && y == global_maximum))
        {
            numerator = -1;
            denominator = 1;
        }
    }

    // Remove the gcd from the fraction
    this->remove_gcd();
}

// Constructor that takes a float argument and converts it to a fraction
ariel::Fraction::Fraction(float float_number) : Fraction(1000 * float_number, 1000) {}

// Overload the "+" operator for two fractions
ariel::Fraction ariel::Fraction::operator+(const Fraction &fraction)
{
    // Calculate the new numerator and denominator for the result
    long long newNum = (long long)(numerator * fraction.denominator) + (long long)(fraction.numerator * denominator);
    long long newDenom = (long long)(denominator) * (long long)(fraction.denominator);

    // If the new numerator or denominator is greater than the global maximum or less than the global minimum, throw an exception
    if (newNum > global_maximum || newNum < global_minimum || newDenom > global_maximum || newDenom < global_minimum)
    {
        throw std::overflow_error(" you have overflow !!!! ");
    }

    return Fraction(newNum, newDenom);
}

// Overload the "+" operator for a float and a fraction
ariel::Fraction Fraction::operator+(float float_number)
{
    // Convert the float to a fraction and use the previous "+" overload to add it to the current fraction
    return (*(this)) + ariel::Fraction(float_number);
}

// Overload the "+" operator for a fraction and a float
ariel::Fraction ariel::operator+(float float_number, const Fraction &fraction)
{
    // Convert the float to a fraction and use the previous "+" overload to add it to the current fraction
    return ariel::Fraction(float_number) + fraction;
}

ariel::Fraction ariel::Fraction::operator-(const Fraction &fraction)
{
    long long newNum = (long long)(numerator * fraction.denominator) - (long long)(fraction.numerator * denominator);
    long long newDenom = (long long)(denominator) * (long long)(fraction.denominator);

    if (newNum > global_maximum || newNum < global_minimum || newDenom > global_maximum || newDenom < global_minimum)
    {
        throw std::overflow_error(" you have overflow !!!! ");
    }
    return ariel::Fraction(newNum, newDenom);
}

ariel::Fraction ariel::Fraction::operator-(float float_number)
{
    return (*(this)) - ariel::Fraction(float_number);
}

ariel::Fraction ariel::operator-(float float_number, const Fraction &fraction)
{
    return ariel::Fraction(float_number) - fraction;
}

ariel::Fraction Fraction::operator*(const Fraction &fraction)
{
    long long newNum = (long long)(numerator) * (long long)(fraction.numerator);
    long long newDenom = (long long)(denominator) * (long long)(fraction.denominator);
    if (newNum > global_maximum || newNum < global_minimum || newDenom > global_maximum || newDenom < global_minimum)
    {
        throw std::overflow_error(" you have overflow !!!!");
    }
    return ariel::Fraction(newNum, newDenom);
}
ariel::Fraction ariel::Fraction::operator*(float float_number)
{
    return (*(this)) * ariel::Fraction(float_number);
}

ariel::Fraction ariel::operator*(float float_number, const Fraction &fraction)
{
    return ariel::Fraction(float_number) * fraction;
}

ariel::Fraction ariel::Fraction::operator/(const Fraction &fraction)
{
    if (!fraction.numerator)
    {
        throw std::runtime_error(" you divide by 0 !!!");
    }
    return (*(this)) * ariel::Fraction(fraction.denominator, fraction.numerator);
}

ariel::Fraction ariel::Fraction::operator/(float float_number)
{
    if (!float_number)
    {
        throw std::runtime_error(" you divide by 0 !!!");
    }
    return (*(this)) / ariel::Fraction(float_number);
}

ariel::Fraction ariel::operator/(float float_number, const Fraction &fraction)
{
    return ariel::Fraction(float_number) / fraction;
}

ariel::Fraction &ariel::Fraction::operator++()
{
    numerator = numerator + denominator;
    return (*(this));
}
ariel::Fraction ariel::Fraction::operator++(int number)
{
    ariel::Fraction temporary_fraction = *this;
    ++(*(this));
    return temporary_fraction;
}

ariel::Fraction &ariel::Fraction::operator--()
{
    numerator = numerator - denominator;
    return (*(this));
}

ariel::Fraction ariel::Fraction::operator--(int number)
{
    ariel::Fraction temporary_fraction = *this;
    --(*(this));
    return temporary_fraction;
}

bool ariel::Fraction::operator==(const Fraction &fraction) const
{
    return numerator == fraction.numerator && denominator == fraction.denominator;
}

bool ariel::Fraction::operator==(float float_number) const
{
    return numerator == float_number * denominator;
}

bool ariel::operator==(float float_number, const Fraction &fraction)
{
    return ariel::Fraction(float_number) == fraction;
}

bool ariel::Fraction::operator>(const Fraction &fraction) const
{
    return numerator * fraction.denominator > fraction.numerator * denominator;
}

bool ariel::Fraction::operator>(float float_number) const
{
    return numerator > float_number * denominator;
}

bool ariel::operator>(float float_number, const Fraction &fraction)
{
    return !(float_number <= fraction);
}

bool ariel::Fraction::operator<(const Fraction &fraction) const
{
    return numerator * fraction.denominator < fraction.numerator * denominator;
}

bool ariel::Fraction::operator<(float float_number) const
{
    return numerator < float_number * denominator;
}

bool ariel::operator<(float float_number, const Fraction &fraction)
{
    return !(float_number >= fraction);
}

bool ariel::Fraction::operator>=(const Fraction &fraction) const
{
    return (*(this)) > fraction || (*(this)) == fraction;
}
bool ariel::Fraction::operator>=(float float_number) const
{
    return (*(this)) > float_number || (*(this)) == float_number;
}

bool ariel::operator>=(float float_number, const Fraction &fraction)
{
    return ariel::Fraction(float_number) >= fraction;
}

bool ariel::Fraction::operator<=(const Fraction &fraction) const
{
    return (*(this)) < fraction || (*(this)) == fraction;
}
bool ariel::Fraction::operator<=(float float_number) const
{
    return (*(this)) < float_number || (*(this)) == float_number;
}

bool ariel::operator<=(float float_number, const Fraction &fraction)
{
    return ariel::Fraction(float_number) <= fraction;
}

ostream &ariel::operator<<(ostream &output_stream, const Fraction &fraction)
{
    output_stream << fraction.numerator << "/" << fraction.denominator;
    return output_stream;
}

istream &ariel::operator>>(istream &input_stream, Fraction &fraction)
{
    if (input_stream >> fraction.numerator >> fraction.denominator)
    {
        if (fraction.denominator == 0)
        {
            throw std::runtime_error(" you divide by 0 !!!");
        }
        fraction.remove_gcd();
        return input_stream;
    }
    else
    {
        throw std::runtime_error(" you should enter two numbers seperated by space !!!");
    }
}
