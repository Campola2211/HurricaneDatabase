/*
 * File: linked_list.cpp
 * Code: Creates a linked list with attributes to remove and insert
 * Name: Nicholas Campola
 * Date: 10/29/2018
 * CPSC 340
 */
#ifndef linked_list_H
#define linked_list_H
#include "single_node.h"
#include <iostream>
#include <string>
using namespace std;

template <class NODETYPE>
class linked_list{

	public:
	    /**
        An overrided equals operator used to set a linked list to another linked list
        @param origList the list to be copied
        @returns linked_list<NODETYPE> 
        */
	    linked_list<NODETYPE> & operator=(const linked_list<NODETYPE> &origList);
	    /**
	     A constructor for a linked list
	     */
		linked_list();
		/**
	     A deconstructor for a linked list
	     */
		~linked_list();
		/**
	     A copy constructor for a linked list
	     @param originalList the list to be copied
	     */
		linked_list(linked_list<NODETYPE> &originalList);
		/**
	     Inserts a value at the end of the linked_list
	     @param value a NODETYPE that is to be inserted
	     @returns bool 
	     */
		bool InsertRear(NODETYPE value);
		/**
	     Inserts a value at the start of the linked_list
	     @param value a NODETYPE that is to be inserted
	     @returns bool 
	     */
		bool InsertFront(NODETYPE value);
		/**
	     Inserts a value at a specific location of the linked_list based on its value
	     @param value a NODETYPE that is to be inserted
	     @returns bool 
	     */
		bool InsertInOrder(NODETYPE value);
		/**
	     Removes a value at a specific location of the linked_list based on its value
	     @param value a NODETYPE that is to be removed
	     @returns bool 
	     */
		bool Remove(NODETYPE & value);
		/**
	     Removes a value at the end of the linked_list
	     @param value a NODETYPE that is to be removed
	     @returns bool 
	     */
        bool RemoveFront(NODETYPE & value);
        /**
	     Inserts a value at the end of the linked_list
	     @param value a NODETYPE that is to be removed
	     @returns bool 
	     */
        bool RemoveRear(NODETYPE & value);
        /**
	     Searches the linked list to see if a value exists
	     @param value a NODETYPE that is to be found
	     @returns bool 
	     */
		bool Search(NODETYPE value);
		/**
	     Checks if the linked list holds any nodes within it
	     @returns bool 
	     */
		bool IsEmpty() const;
		/**
	     Prints out all the contents of a linked list
	     */
		void PrintAll();
	private:
		ListNode<NODETYPE> *first;
		ListNode<NODETYPE> *current;
		ListNode<NODETYPE> *last;

};

#include "linked_list.cpp"
#endif