#pragma once
#include <vector>
#include "List.h"
#include <cmath>


class Poly
{
public:
	Poly();								//default constructor
	Poly(Rational);						//constructor to skalar 
	Poly(int, Rational);				//constructor to monom
	Poly(const std::vector<Rational>&); //constructor to vactor

	Poly& operator+=(const Poly&);
	Poly& operator-=(const Poly&);
	Poly& operator*=(const Poly&);

	Rational operator[](int)const;
	Rational operator()(Rational)const;

	//get & set functions
	List& getPoly() { return m_poly; } //bad
	Node* getPolyHead()const { return m_poly.getHead(); }
	int getPolySize()const { return m_poly.getSize(); }
	int deg() const { return((m_deg >= 0) ? m_deg : -1); }
	void setDeg(int deg) { m_deg = deg; }

private:
	int m_deg;
	List m_poly;
};

bool operator==(const Poly&, const Poly&);
bool operator!=(const Poly&, const Poly&);

std::ostream& operator<<(std::ostream&, const  Poly&);//ostream polynom

Poly operator * (const Poly&, const Poly&);		//multiply two polynoms
Poly operator * (const Poly&, const Rational&); //multiply polynom in scalar
Poly operator * (const Rational&, const Poly&); //multiply polynom in scalar
Poly operator + (const Poly&, const Poly&);		//add two polynoms
Poly operator - (const Poly&, const Poly&);		//sub two polynoms	
Poly operator % (const Poly&, const Poly&);		//modulo two polynoms
Poly operator / (const Poly&, const Poly&);		//divide two polynoms

Poly gcd(const Poly&, const Poly&, Poly&);
//help add funcions
void calcSum(const Poly&, const Poly& , Poly&);
void addVal(Node*, Node*, Poly&);
void insertToPoly(Rational, Poly&, int);
