#pragma once

#include <limits>
#include <iostream>

using namespace std;

namespace ariel
{
    class Fraction
    {
    private:
        int numerator;
        int denominator;
        void remove_gcd();
        int global_maximum = numeric_limits<int>::max();
        int global_minimum = numeric_limits<int>::min();

    public: 
        Fraction() : numerator(0), denominator(1) {}
        Fraction(int, int);
        Fraction(float);

        int getNumerator() const
        {
            return numerator;
        }

        int getDenominator() const
        {
            return denominator;
        }

        Fraction operator+(const Fraction &);
        Fraction operator+(float);
        friend Fraction operator+(float, const Fraction &);

        Fraction operator-(const Fraction &);
        Fraction operator-(float);
        friend Fraction operator-(float, const Fraction &);

        Fraction operator*(const Fraction &);
        Fraction operator*(float);
        friend Fraction operator*(float, const Fraction &);

        Fraction operator/(const Fraction &);
        Fraction operator/(float);
        friend Fraction operator/(float, const Fraction &);

        Fraction &operator++();
        Fraction operator++(int);

        Fraction &operator--();
        Fraction operator--(int);

        bool operator==(const Fraction &) const;
        bool operator==(float) const;
        friend bool operator==(float, const Fraction &);

        bool operator>(const Fraction &) const;
        bool operator>(float) const;
        friend bool operator>(float, const Fraction &);

        bool operator<(float) const;
        bool operator<(const Fraction &) const;
        friend bool operator<(float, const Fraction &);

        bool operator>=(const Fraction &) const;
        bool operator>=(float) const;
        friend bool operator>=(float, const Fraction &);

        bool operator<=(const Fraction &) const;
        bool operator<=(float) const;
        friend bool operator<=(float, const Fraction &);

        friend ostream &operator<<(ostream &, const Fraction &);
        friend istream &operator>>(istream &, Fraction &);
    };
}
