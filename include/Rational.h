#pragma once
#include <iostream>
#include <iosfwd>
#include <numeric>

class Rational {
public:
	Rational(int = 0, int = 1);

	Rational& operator/=(const Rational&);
	Rational& operator*=(const Rational&);
	Rational& operator+=(const Rational&);
	Rational& operator-=(const Rational&);

	int getNumerator()const {return m_numerator; }
	int getDenominator()const {return m_denominator; }
	double getFloatPointVal()const { return double(getNumerator()) / double(getDenominator()); }

private:
	int m_numerator;
	int m_denominator;
};

//ostream operator
std::ostream& operator<<(std::ostream&, const Rational&);

//mathematics operators
Rational operator/(const Rational&, const Rational&);
Rational operator*(const Rational&, const Rational&);
Rational operator+(const Rational&, const Rational&);
Rational operator-(const Rational&, const Rational&);

//Unarys operators
Rational operator-(const Rational&);	
Rational operator+(const Rational&);

//boolian operators
bool operator==(const Rational&, const Rational&);
bool operator!=(const Rational&, const Rational&);
bool operator<(const Rational&, const Rational&);
bool operator>(const Rational&, const Rational&);
bool operator>=(const Rational&, const Rational&);
bool operator<=(const Rational&, const Rational&);
