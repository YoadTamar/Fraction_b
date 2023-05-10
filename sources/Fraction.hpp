#pragma once

#include <limits> 
#include <iostream> 

using namespace std; 

namespace ariel { 

    class Fraction { 
    private:  // private members
        int numerator; 
        int denominator;  
        void remove_gcd();  // function to remove the gcd
        int global_maximum = numeric_limits<int>::max();  // maximum value of int
        int global_minimum = numeric_limits<int>::min();  // minimum value of int

    public:  // public members
        // constructors
        Fraction() : numerator(0), denominator(1) {}  // default constructor
        Fraction(int, int);  
        Fraction(float); 

        // getter functions
        int getNumerator() const
        {
            return numerator;
        }

        int getDenominator() const
        {
            return denominator;
        }


        // arithmetic operators
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

        // increment and decrement operators
        Fraction &operator++(); 
        Fraction operator++(int); 

        Fraction &operator--(); 
        Fraction operator--(int);  

        // comparison operators
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
