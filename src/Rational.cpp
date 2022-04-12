#include "Rational.h"


Rational::Rational(int n, int d)
{
	if (n < 0 && d < 0){
		n = -n;
		d = -d;
	}
	int c_div = std::gcd(n, d);
	m_numerator = n / c_div;
	m_denominator = d / c_div;
}

//=============================================================================
std::ostream& operator<<(std::ostream& os, const Rational& num)
{
	return os << num.getNumerator() << "/" << num.getDenominator();
}

//=============================================================================
Rational operator+(const Rational& a, const Rational& b)
{
	return Rational(a.getNumerator() *b.getDenominator() +
		b.getNumerator() *a.getDenominator(),a.getDenominator() *b.getDenominator());
}

//=============================================================================
Rational operator-(const Rational& a, const Rational& b)
{
	return Rational(a.getNumerator()*b.getNumerator() -b.getNumerator() *a.getDenominator(),
						a.getDenominator() *b.getDenominator());
}

//=============================================================================
Rational operator*(const Rational& a, const Rational& b)
{
	return Rational(a.getNumerator() *b.getNumerator(),
					a.getDenominator() *b.getDenominator());
}

//=============================================================================
Rational operator/(const Rational& a, const Rational& b)
{
	return Rational(a.getNumerator() *b.getDenominator(),a.getDenominator() *b.getNumerator());
}

//=============================================================================
Rational operator+(const Rational& a)
{
	return Rational(+a.getNumerator(), a.getDenominator());
}

//=============================================================================
Rational operator-(const Rational& a)
{
	return Rational(-a.getNumerator(), a.getDenominator());
	//return Rational(-a.getNumerator(), a.getDenominator());
}

//=============================================================================
Rational& Rational::operator/=(const Rational& a)
{
	return *this = *this / a;
}
//=============================================================================
Rational& Rational::operator*=(const Rational& a)
{
	return *this = *this * a;
}

//=============================================================================
Rational& Rational::operator+=(const Rational& a)
{
	return *this = *this + a;
}

//=============================================================================
Rational& Rational::operator-=(const Rational& a)
{
	return *this = *this - a;
}

//=============================================================================
bool operator==(const Rational& l, const Rational& r)
{
	return (l.getNumerator() == r.getNumerator() && l.getDenominator() == r.getDenominator());
}

//=============================================================================
bool operator!=(const Rational& l, const Rational& r)
{
	return !(l == r);
}

//=============================================================================
bool operator<(const Rational& l, const Rational& r)
{
	return l.getFloatPointVal() < r.getFloatPointVal();
}

//=============================================================================
bool operator>(const Rational& l, const Rational& r)
{
	return l<r;
}

//=============================================================================
bool operator>=(const Rational& l, const Rational& r)
{
	return l.getFloatPointVal() >= r.getFloatPointVal();
}

//=============================================================================
bool operator<=(const Rational& l, const Rational& r)
{
	return l>=r;
}
