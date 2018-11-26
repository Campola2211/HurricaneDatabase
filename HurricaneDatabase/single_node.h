/*
 * File: single_node.cpp
 * Code: Represents a node within the linked list
 * Name: Nicholas Campola
 * Date: 10/29/2018
 * CPSC 340
 */

#ifndef NODE
#define NODE


template <class NODETYPE> class linked_list;

template <class NODETYPE>
class ListNode{
	friend class linked_list<NODETYPE>;
public:
	ListNode() { next = 0; }
	ListNode(const NODETYPE &);
	NODETYPE getData() const;
private:
	NODETYPE data;
	ListNode <NODETYPE>*next;
};
#include "single_node.cpp"

#endif