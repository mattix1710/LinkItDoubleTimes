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
	// TODO: use unique_ptr or other version (??)
	~List() {};

	void add(T);
	void push(T);
	void addAt(T, int);
	//Link<T>* get() { return last; };
	//Link<T>* getAt(uint);
	T get() { return last->val(); };
	T getAt(uint position);
	void listData();
};