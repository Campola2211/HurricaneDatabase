/*
 * File: single_node.cpp
 * Code: Represents a node within the linked list
 * Name: Nicholas Campola
 * Date: 10/29/2018
 * CPSC 340
 */

#include "single_node.h"
#ifndef NODE_CPP
#define NODE_CPP

template <class NODETYPE>
ListNode<NODETYPE>::ListNode(const NODETYPE &info){
	data = info;
	next = 0;
}

template <class NODETYPE>
NODETYPE ListNode<NODETYPE>::getData() const{
	return data;
}
#endif
