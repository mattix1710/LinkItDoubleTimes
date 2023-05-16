#include <iostream>

#include "List.h"
#include "Link.h"

#define uint unsigned int

template <class T>
T List<T>::get_at(uint position) {
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

template<class T>
void List<T>::add_at(T val, int pos)
{
	if (pos > this->quantity || pos < 0) {
		std::cout << "Selected position is out of range!" << std::endl;
		return;
	}

	Link<T>* node = nullptr;
	
	if (pos == this->quantity) {
		this->add(val);
		return;
	}
	else if (pos == 0) {
		this->push(val);
		return;
	}
	else if (pos > this->quantity/2) {
		node = this->last;
		
		for (uint pivot = this->quantity-1; pivot > pos; pivot--) {
			node = node->getPrevious();
		}

		Link<T>* newNode = new Link<T>(val, node, node->getPrevious());
		node->getPrevious()->setNext(newNode);
		node->setPrevious(newNode);
	}
	else {
		node = this->first;
		for (uint pivot = this->quantity; pivot < pos; pivot++) {
			node = node->getNext();
		}
		Link<T>* newNode = new Link<T>(val, node, node->getPrevious());
		node->getPrevious()->setNext(newNode);
		node->setPrevious(newNode);
	}
	this->quantity++;
	std::cout << "Value of " << val << " has been inserted at position of " << pos << "!" << std::endl;
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

template<class T>
T List<T>::pop()
{
	Link<T>* toRemove = this->first;
	T aux = toRemove->getVal();
	this->first = this->first->getNext();
	this->first->setPrevious(nullptr);
	delete toRemove;
	this->quantity--;

	return aux;
}

template<class T>
T List<T>::remove_at(uint position)
{
	try {
		if (this->quantity > 0 && position >= 0 && position < this->quantity) {
			Link<T>* node = nullptr;
			T val;
			if (position == this->quantity) {
				// if last node - change assigned pointer and set next pointer to nullptr
				node = this->last;
				this->last = this->last->getPrevious();
				this->last->setNext(nullptr);
				val = node->getVal();
				delete node;
			}
			else if (position == 0) {
				node = this->first;
				this->first = this->first->getNext();
				this->first->setPrevious(nullptr);
				val = node->getVal();
				delete node;
			}
			else if (position > this->quantity / 2) {
				node = this->last;

				for (uint pivot = this->quantity - 1; pivot > position; pivot--) {
					node = node->getPrevious();
				}

				val = node->getVal();
				node->getPrevious()->setNext(node->getNext());
				node->getNext()->setPrevious(node->getPrevious());
				delete node;
			}
			else {
				node = this->first;

				for (uint pivot = 0; pivot < position; pivot++) {
					node = node->getNext();
				}

				val = node->getVal();
				node->getPrevious()->setNext(node->getNext());
				node->getNext()->setPrevious(node->getPrevious());
				delete node;
			}

			this->quantity--;
			return val;
		}
		else {
			// if there is no element in the list or selected position doesn't match currents list size
			throw nullptr;
		}
	}
	catch (...) {
		std::cout << "ERROR: Invalid argument position!" << std::endl;
	}
	
}

template <class T>
T List<T>::get() {
	try {
		if (this->quantity > 0) {
			return this->last->getVal();
		}
		else {
			// if there is no element in the list
			throw nullptr;
		}
	}
	catch (...) {
		std::cout << "ERROR: No element in the list!" << std::endl;
	}
}

template <class T>
void List<T>::sort() {
	if (this->quantity <= 1) {
		// List is already sorted or empty
		return;
	}

	bool swapped = true;
	while (swapped) {
		swapped = false;
		Link<T>* current = this->first;
		Link<T>* previous = nullptr;

		while (current != nullptr && current->getNext() != nullptr) {
			if (current->getVal() > current->getNext()->getVal()) {
				// Swap values
				T temp = current->getVal();
				current->setVal(current->getNext()->getVal());
				current->getNext()->setVal(temp);
				swapped = true;
			}

			previous = current;
			current = current->getNext();
		}
	}
} 
template  <class T>
void List<T>::display() {
	std::cout << "List: ";
	for (Link<T>* currNode = this->first; currNode != nullptr; currNode = currNode->getNext()) {
		  std::cout << currNode->getVal() << " ";
	}
	 std::cout << std::endl;
}







