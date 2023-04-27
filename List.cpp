#include <iostream>

#include "List.h"
#include "Link.h"

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

// ADDS A NEW ELEMENT AT THE BEGINNING OF THE LIST
template<class T>
void List<T>::push(T val)
{
	Link<T>* node = new Link<T>(val, this->first, nullptr);

	// if there is no node in the list yet
	if (this->first == nullptr) {
		this->first = node;
		this->last = node;
	}
	else {
		this->first->setPrevious(node);
		this->first = node;
	}
	this->quantity++;

	std::cout << "Added element " << val << " to the beginning of the list!" << std::endl;
}

template <class T>
void List<T>::add(T val) {
	// if there is no element in the list yet
	Link<T>* node = new Link<T>(val, nullptr, this->last);

	// if there is no node in the list yet
	if (this->first == nullptr) {
		this->first = node;
		this->last = node;
	}
	else {
		this->last->setNext(node);
		this->last = node;
	}
	this->quantity++;

	std::cout << "Added element " << val << " to the end of the list!" << std::endl;
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