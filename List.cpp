//#include <iostream>
//
//#include "List.h"
//#include "Link.h"
//
//#define uint unsigned int
//
//template <class T>
//T List<T>::getAt(uint position) {
//	// first element is at position 0
//	uint pivot = this->quantity; // 2
//	Link<T>* current = nullptr;
//
//	// if the seeked element is closer to the end of the list
//	if (position > pivot) {
//		pivot = this->quantity;
//		current = this->last;
//		while (position != pivot) {
//			current = current->getPrevious();
//			pivot--;
//		}
//	}
//	// if the seeked element is closer to the start of the list
//	else {
//		pivot = 0;
//		current = this->first;
//		while (position != pivot) {
//			current = current->getNext();
//			pivot++;
//		}
//	}
//	return current->getVal();
//}
//
//template <class T>
//void List<T>::add(T val) {
//	// if there is no element in the list yet
//	Link<T>* node = Link<T>(val, nullptr, this->last);
//
//	if (this->first == nullptr) {
//		this->first = node;
//	}
//	else {
//		this->last = node;
//	}
//	this->quantity++;
//}
//
//template <class T>
//void List<T>::listData() {
//	std::cout << "==::==" << std::endl;
//	for (Link<T>* currNode = this->first; currNode != nullptr; currNode = currNode->getNext()) {
//		std::cout << currNode->getVal() << " | ";
//	}
//	std::cout << "::==::" << std::endl;
//}