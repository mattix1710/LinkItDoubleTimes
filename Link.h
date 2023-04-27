#pragma once
#include <iostream>

template <class T> class List;			// declaration of a friend template class List

template <class T>
class Link {
	T val;
	Link<T>* next;
	Link<T>* previous;

public:
	Link(T val_, Link* next_ = nullptr, Link* previous_ = nullptr) : val(val_), next(next_), previous(previous_) {};
	~Link() {};

	Link<T>* insert_after(T&);
	Link<T>* insert_before(T&);

	T getVal() { return val; };
	Link* getNext() { return next; };
	Link* getPrevious() { return previous; };
	void setNext(Link<T>*);
	void setPrevious(Link<T>*);

	friend class List<T>;
};

template <class T>
Link<T>* Link<T>::insert_after(T& toInsert) {
	next = new Link<T>(toInsert, next, this);
	return next;
}

template <class T>
Link<T>* Link<T>::insert_before(T& toInsert) {
	previous = new Link<T>(toInsert, this, previous);
	return previous;
}

template <class T>
void Link<T>::setNext(Link<T>* next) {
	this->next = next;
}

template <class T>
void Link<T>::setPrevious(Link<T>* previous) {
	this->previous = previous;
}