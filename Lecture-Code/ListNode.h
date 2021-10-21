#ifndef LIST_NODE_H
#define LIST_NODE_H

template<typename T>
class ListNode
{
public:
    ListNode(T i, ListNode<T>* pPrevNode, ListNode<T>* pNextNode);
    ~ListNode() {};

    T item;
    ListNode<T>* pPrevNode, *pNextNode;

private:
};

template<typename T>
ListNode<T>::ListNode(T i, ListNode<T>* pPrevNode, ListNode<T>* pNextNode)
    : item(i), pPrevNode(pPrevNode), pNextNode(pNextNode)
{
}

#endif 

