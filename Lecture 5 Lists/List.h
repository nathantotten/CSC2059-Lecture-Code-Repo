#ifndef LIST_H
#define LIST_H

#include "ListNode.h"
#include <iostream>

template <typename T>
class List
{
public:
	List();
	~List();

	T insert_front(T item);	// insert item at front
	T insert_end(T item);	// insert item at end
	T insert(int p, T item); // insert item at p

	T remove_front();	// delete & return item at front
	T remove_end();		// delete & return item at end
	T remove(int p);	// delete & return item at p

	T get(int p); // return item at p, no delete
	T get_next(); // return pCurrentNode->item & move pCurrentNode to pCurrentNode->pNextNode
	T get_prev(); // return pCurrentNode->item & move pCurrentNode to pCurrentNode->pPrevNode

	void setp(int p); // set pointer pCurrentNode to node at p
	void setp_first() { pCurrentNode = pFirstNode; }  // inline
	void setp_last() { pCurrentNode = pLastNode; }

	int size() { return listSize; }

private:
	ListNode<T>* pFirstNode, *pLastNode, *pCurrentNode;
	int listSize;	// number of items in the list
};

template <typename T>
List<T>::List()
{
	pFirstNode = pLastNode = pCurrentNode = NULL;
	listSize = 0;
}

template<typename T>
List<T>::~List()
{
	pCurrentNode = pFirstNode;
	while (pCurrentNode != NULL) {
		ListNode<T>* pNewCurrentNode = pCurrentNode->pNextNode;
		delete pCurrentNode;
		pCurrentNode = pNewCurrentNode;
	}
}

template<typename T>
T List<T>::insert_front(T item)
{
	pFirstNode = new ListNode<T>(item, NULL, pFirstNode);
	if (listSize > 0)
		pFirstNode->pNextNode->pPrevNode = pFirstNode;
	else 
		pLastNode = pFirstNode;
	listSize++;
	return item;
}

template<typename T>
T List<T>::insert_end(T item)
{
	if (listSize == 0)
		return insert_front(item);
	pLastNode = new ListNode<T>(item, pLastNode, NULL);
	pLastNode->pPrevNode->pNextNode = pLastNode;
	listSize++;
	return item;
}

template<typename T>
T List<T>::insert(int p, T item)
{
	if (p == 0)
		return insert_front(item);
	else if (p == listSize)
		return insert_end(item);

	setp(p); // point pCurrentNode to position p
	ListNode<T>* pNewNode = new ListNode<T>(item, pCurrentNode->pPrevNode, pCurrentNode);
	pCurrentNode->pPrevNode->pNextNode = pNewNode;
	pCurrentNode->pPrevNode = pNewNode;
	listSize++;
	return item;
}

template<typename T>
T List<T>::remove_front()
{
	if (pFirstNode != NULL) {
		T item = pFirstNode->item;
		ListNode<T>* pNewFirstNode = pFirstNode->pNextNode;
		delete pFirstNode;
		pFirstNode = pNewFirstNode;
		if(pFirstNode != NULL) 
			pFirstNode->pPrevNode = NULL;
		listSize--;
		if (listSize == 0) 
			pLastNode = NULL;
		return item;
	}
	std::cout << "List is empty. Exit." << std::endl;
	exit(0);
}

template<typename T>
T List<T>::remove_end()
{
	if (listSize == 1)
		return remove_front();
	T item = pLastNode->item;
	ListNode<T>* pNewLastNode = pLastNode->pPrevNode;
	delete pLastNode;
	pLastNode = pNewLastNode;
	pLastNode->pNextNode = NULL;
	listSize--;
	return item;
}

template<typename T>
T List<T>::remove(int p)
{
	if (p == 0)
		return remove_front();
	else if (p == listSize - 1)
		return remove_end();

	setp(p); // point pCurrentNode to position p
	T item = pCurrentNode->item;
	pCurrentNode->pPrevNode->pNextNode = pCurrentNode->pNextNode;
	pCurrentNode->pNextNode->pPrevNode = pCurrentNode->pPrevNode;
	delete pCurrentNode;
	listSize--;
	return item;
}

template<typename T>
T List<T>::get(int p)
{
	setp(p);
	return pCurrentNode->item;
}

template<typename T>
T List<T>::get_next()
{
	if (pCurrentNode != NULL) {
		T item = pCurrentNode->item;
		pCurrentNode = pCurrentNode->pNextNode;
		return item;
	}
	std::cout << "List is empty. Exit." << std::endl;
	exit(0);
}

template<typename T>
T List<T>::get_prev()
{
	if (pCurrentNode != NULL) {
		T item = pCurrentNode->item;
		pCurrentNode = pCurrentNode->pPrevNode;
		return item;
	}
	std::cout << "List is empty. Exit." << std::endl;
	exit(0);
}

template<typename T>
void List<T>::setp(int p)
{
	if (p < 0 || p >= listSize) {
		std::cout << "Unable to reach list position " << p << std::endl;
		exit(0);
	}
	
	pCurrentNode = pFirstNode;
	while (p-- > 0)
		pCurrentNode = pCurrentNode->pNextNode;
}

#endif
