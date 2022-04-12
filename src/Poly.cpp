#include "Poly.h"


//default constructor
Poly::Poly() :m_deg(0), m_poly() {}


Poly::Poly(Rational scalar)		//scalar constroctor  
{

	m_poly.insertFirst(0, scalar);
}


Poly::Poly(int deg, Rational coeff)		//constructor of monom
{
	m_deg = deg;
	m_poly.insertFirst(deg, coeff);
}

Poly::Poly(const std::vector<Rational>& coeffs)	//constructor of vactor
{
	for (int i = 0, j = int(coeffs.size()-1) ; i < int(coeffs.size()) && j >= 0 ; i++, j--){

		if (coeffs[i] != 0)
			m_poly.insert(j, coeffs[i]);
	}
	m_deg = m_poly.getHead()->getDeg();
}

bool operator==(const Poly& a, const Poly& b)
{
	return a.deg() == b.deg();
}

bool operator!=(const Poly& a, const Poly& b)
{
	return !(a == b);
}

//add to *this Polynom operator
Poly& Poly::operator+=(const Poly& other)
{
	return(*this = *this + other);
}

//sub from *this polynom operator
Poly& Poly::operator-=(const Poly& other)
{
	return *this = *this + other * (-1);
}

//multiply to *this polynom operator
Poly& Poly::operator*=(const Poly& other)
{
	return(*this = *this * other);
}

//accses operator
Rational Poly::operator[](int deg) const
{
	for (Node* p = getPolyHead(); p != nullptr; p = p->getNext())
		if (p->getDeg() == deg)
			return p->getCoeff();
	return 0;
}

//activate operator
Rational Poly::operator()(Rational a) const
{
	Rational val = 0;
	for (Node* p = getPolyHead(); p != nullptr; p = p->getNext())
		val += p->getCoeff() * pow(a.getFloatPointVal(), p->getDeg());

	return val;
}

//print operator
std::ostream& operator<<(std::ostream& os, const Poly& other)
{
	Node* p = other.getPolyHead();

	if (other.deg() == 0)
		return os << 0;

	for (; p != nullptr; p = p->getNext()) {

		if (p->getCoeff() != 0 && p->getDeg() == 0)
			os << p->getCoeff();

		else if (p->getCoeff() == 1)
			os << "x^" << p->getDeg();

		else os << p->getCoeff() << "x^" << p->getDeg();

		if (p->getNext() != nullptr && p->getNext()->getCoeff() > 0)
			os << " + ";
	}
	os << std::endl;
	return os;
}

//multiply two polinums operator
Poly operator*(const Poly& a, const Poly& b)
{
	int deg;
	Rational coeff;
	Poly c;
	Node* aPtr, * bPtr;

	for (aPtr = a.getPolyHead(); aPtr != nullptr; aPtr = aPtr->getNext()) {
		for (bPtr = b.getPolyHead(); bPtr != nullptr; bPtr = bPtr->getNext()) {

			deg = aPtr->getDeg() + bPtr->getDeg();
			coeff = aPtr->getCoeff() * bPtr->getCoeff();

			if (coeff != 0) {
				Poly temp(deg, coeff);
				c += temp;
			}
		}
	}

	return Poly(c);
}

//multiply polynom operator in scalar-from right
Poly operator*(const Poly& a, const Rational& scalar)
{
	Poly b;
	int deg;
	Rational coeff;
	Node* Ptr = a.getPolyHead();
	while (Ptr)
	{
		deg = Ptr->getDeg();
		coeff = Ptr->getCoeff() * scalar;

		if (coeff != 0) {
			Poly temp(deg, coeff);
			b += temp;
		}
		Ptr = Ptr->getNext();
	}
	return b;
}

//multiply polynom operator in scalar-from left
Poly operator*(const Rational& scalar, const Poly& a)
{
	return a * scalar;
}

//add operator of two poly
Poly operator+(const Poly& a, const Poly& b)
{
	Poly sum;
	Node* aPtr = a.getPolyHead();
	Node* bPtr = b.getPolyHead();

	calcSum(a, b, sum);

	if (sum.getPolyHead() != nullptr)
		sum.setDeg(sum.getPolyHead()->getDeg());
	return sum;
}

//help func for add operator - calculate sums
void calcSum(const Poly& a, const Poly& b, Poly& sum)
{
	Node* aPtr = a.getPolyHead();
	Node* bPtr = b.getPolyHead();

	while (aPtr != nullptr && bPtr != nullptr) {

		if (aPtr->getDeg() == bPtr->getDeg()) {

			insertToPoly(aPtr->getCoeff() + bPtr->getCoeff(), sum, aPtr->getDeg());
			aPtr = aPtr->getNext();
			bPtr = bPtr->getNext();
		}
		else if (aPtr->getDeg() < bPtr->getDeg()) {

			insertToPoly(bPtr->getCoeff(), sum, bPtr->getDeg());
			bPtr = bPtr->getNext();
		}
		else if (aPtr->getDeg() > bPtr->getDeg()) {

			insertToPoly(aPtr->getCoeff(), sum, aPtr->getDeg());
			aPtr = aPtr->getNext();
		}
	}
	addVal(aPtr, bPtr, sum);
}

//help func for calculate sums
void addVal(Node* aPtr, Node* bPtr, Poly& sum)
{
	while (aPtr != nullptr) {
		insertToPoly(aPtr->getCoeff(), sum, aPtr->getDeg());
		aPtr = aPtr->getNext();
	}
	while (bPtr != nullptr) {
		insertToPoly(bPtr->getCoeff(), sum, bPtr->getDeg());
		bPtr = bPtr->getNext();
	}
}

//for the plus operator
void insertToPoly(Rational coeff, Poly& sum, int deg)
{
	if (coeff != 0)
		sum.getPoly().insert(deg, coeff);
}

//calculates the subtraction of two polinums
Poly operator-(const Poly& a, const Poly& b)
{
	return Poly(a + b * (-1));
}

//calculates the remain between two polinums
Poly operator%(const Poly& a, const Poly& b)
{
	Poly r;
	Poly c = gcd(a, b, r);
	return r;
}

//calculates the division of two polinums
Poly operator/(const Poly& a, const Poly& b)
{
	Poly r;
	return gcd(a, b, r);
}

//gcd polynom of two polynoms
Poly gcd(const Poly& a, const Poly& b, Poly& remain)
{
	Poly poly;
	int deg = b.getPolyHead()->getDeg();
	Rational coeff = b.getPolyHead()->getCoeff();
	remain = a;

	while (remain.deg() >= deg) {

		//if deg = 0 -> skalar
		if (remain.deg()-deg == 0) {
			Poly s(remain.getPolyHead()->getCoeff() / coeff);
			poly += s;
			remain.setDeg(0);
		}
		else {
			Poly second(remain.deg()-deg, remain.getPolyHead()->getCoeff() / coeff);
			poly += second;
			second *= b;
			remain -= second;
		}
	}
	return poly;
}
