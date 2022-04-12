#include "List.h"



List::List() :m_head(nullptr), m_size(0) {}	//default constractor

//=============================================================================
List::~List()	//decstructor
{
	Node *head, *temp;
	head = m_head;

	while (head != nullptr) {
		temp = head;
		head = head->getNext();
		delete temp;
	}
}

//=============================================================================
List::List(const List &other)	//copy constructor
{
	Node *head = other.m_head;

	if (head == nullptr)
		return;
	
	insertFirst(head->getDeg(), head->getCoeff());

	for (head = head->getNext() ; head != nullptr ; head = head->getNext()) {
		insert(head->getDeg() , head->getCoeff());

		if (head->getNext() == nullptr)
			break;
	}
	m_size = other.m_size;
}

//=============================================================================
List& List::operator=(const List &other)	//assign operator
{
	Node *head = other.m_head;

	if (head == nullptr)
		return *this;

	insertFirst(head->getDeg(), head->getCoeff());

	for (head = head->getNext(); head != nullptr; head = head->getNext()) {
		insert(head->getDeg(), head->getCoeff());

		if (head->getNext() == nullptr)
			break;
	}
	m_size = other.m_size;
	return *this;
}

//=============================================================================
void List::insertFirst(int deg, Rational coeff)	   //insert first to linked list
{
	m_head = new Node(deg, coeff, NULL);

	if (m_head == nullptr) {
		std::cerr << "Cannot allocate memory\n";
		exit(EXIT_FAILURE);
	}
	m_size++;
}

//=============================================================================
void List::insert(int deg, Rational coeff)	//insert new item to linked list
{
	Node *head = m_head, *temp;

	if (head == nullptr)
	{
		insertFirst(deg, coeff);
		return;
	}

	while (head->getNext() != nullptr)
		head = head->getNext();

	temp = new Node(deg, coeff, nullptr);
	if (temp == nullptr) 
	{
		std::cerr << "Cannot allocate memory\n";
		exit(EXIT_FAILURE);
	}
	head->setNext(temp);

	m_size++;
}