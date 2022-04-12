#pragma once
#include "Node.h"

using std::cout;

class List
{
public:
	List();							//default constructor
	~List();						//destructor
	List(const List&);				//copy constructor
	List& operator=(const List&);   //assign operator

	Node *getHead()const { return m_head; }
	int getSize()const   { return m_size; }

	void insertFirst(int, Rational);
	void insert(int, Rational);
	
private:
	Node* m_head;
	int m_size;
};

