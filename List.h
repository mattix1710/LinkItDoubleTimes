#pragma once
#include <iostream>
#include "Link.h"

#define uint unsigned int

template <class T>
class List {
protected:
	Link<T>* first;
	Link<T>* last;
	uint quantity = 0;

public:
	List() { first = last = nullptr; };		// if there are no arguments provided
	//List(Link<T>* first_ = nullptr, Link<T>* last_ = nullptr) : first(first_), last(last_) {};

	// TODO: delete all pointers used in list when deleting list
	~List() {
		Link<T>* currNode;
		// while currNode won't reach the end of the list
		while (this->first != nullptr) {
			currNode = this->first;
			this->first = currNode->getNext();
			delete currNode;
		}
		this->first = nullptr;
		this->last = nullptr;
	};

	void add(T);					// add new element at the beginning of the list
	void push(T);					// add new element at the end of the list
	void add_at(T val, int pos);	// add new element at pos in the list
	T get();						// get the last element from the list
	T get_at(uint position);		// get the element at position in the list
	T pop();						// pop the element from the beginning of the list and return the value
	T remove_at(uint position);		// remove the element from the position in the list and return the value
	void sort();						// sorts a list 
	void display();					// Displays a list
	// AUXILIARY
	void listData();
};