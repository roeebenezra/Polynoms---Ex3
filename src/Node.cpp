#include "Node.h"


Node::Node()										//default constractor
	:m_deg(0), m_coeff(0),m_next(nullptr) {}

//=============================================================================

Node::Node(int deg, Rational coeff, Node* next)		//constractor
	: m_deg(deg), m_coeff(coeff), m_next(next) {}

//=============================================================================

bool Node::operator!=(const Node &other) const		//different operator
{
	if (*this == other)
		return false;
	return true;
}

//=============================================================================

bool Node::operator==(const Node &other) const		//equal operator
{
	if (m_deg != other.m_deg || m_coeff != other.m_coeff)
		return false;
	return true;
}

