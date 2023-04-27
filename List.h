#pragma once
#include <iostream>
#include "Link.h"
//#include "Iterator.h"

#define uint unsigned int

//template <class T> class Iterator;

template <class T>
class List {
protected:
	Link<T>* first;
	Link<T>* last;
	uint quantity = 0;

public:
	List() { first = last = nullptr; };		// if there are no arguments provided
	List(Link<T>* first_ = nullptr, Link<T>* last_ = nullptr) : first(first_), last(last_) {};

	// TODO: delete all pointers used in list when deleting list
	// TODO: use unique_ptr or other version
	~List() {};

	void add(T);
	//void push(T);
	//void addAt(T, int);
	Link<T>* get() { return last; };
	//Link<T>* getAt(uint);
	T getAt(uint position);
	void listData();


	//Link<T>* getFirst() { return first; };


	//friend class Iterator<T>;

};


#define uint unsigned int

template <class T>
T List<T>::getAt(uint position) {
	// first element is at position 0
	uint pivot = this->quantity; // 2
	Link<T>* current = nullptr;

	// if the seeked element is closer to the end of the list
	if (position > pivot) {
		pivot = this->quantity;
		current = this->last;
		while (position != pivot) {
			current = current->getPrevious();
			pivot--;
		}
	}
	// if the seeked element is closer to the start of the list
	else {
		pivot = 0;
		current = this->first;
		while (position != pivot) {
			current = current->getNext();
			pivot++;
		}
	}
	return current->getVal();
}

// TODO: repair that method! - it doesn't add new elements to the list
template <class T>
void List<T>::add(T val) {
	// if there is no element in the list yet
	Link<T>* node = new Link<T>(val, nullptr, this->last);

	if (this->first == nullptr) {
		this->first = node;
		this->last = node;
	}
	else {
		this->last->setNext(node);
		this->last = node;
	}
	this->quantity++;

	std::cout << "Added element " << val << " to the list!" << std::endl;
}

template <class T>
void List<T>::listData() {
	std::cout << "==::==" << std::endl;
	for (Link<T>* currNode = this->first; currNode != nullptr; currNode = currNode->getNext()) {
		std::cout << currNode->getVal() << " | ";
	}
	std::cout << std::endl << "::==::" << std::endl;
	std::cout << "Quantity: " << this->quantity << std::endl;
}