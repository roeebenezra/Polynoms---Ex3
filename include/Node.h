#pragma once
#include "Rational.h"

#include <iostream>
#include <cstdlib> 


class Node
{
public:
	Node();											//default constractor
	Node(int = 0, Rational = 0, Node* = nullptr);   //constractor

	//oprator functions
	bool operator!=(const Node&)const;
	bool operator==(const Node&)const;

	//set function
	void setNext(Node* next){ m_next = next; }

	//get functions
	Node* getNext()const { return m_next; }
	int getDeg()const { return m_deg; }
	Rational getCoeff()const { return m_coeff; }

private:
	int m_deg;
	Rational m_coeff;
	Node *m_next;
};

