/*
 * File: linked_list.cpp
 * Code: Creates a linked list with attributes to remove and insert
 * Name: Nicholas Campola
 * Date: 10/29/2018
 * CPSC 340
 */
#ifndef LIST_CPP
#define LIST_CPP
#include "linked_list.h"
#include <iostream>
#include <string>
using namespace std;


template <class NODETYPE>
linked_list<NODETYPE>::linked_list() {
        first = NULL;
        current = NULL;
        last = NULL;
}

template <class NODETYPE>
linked_list<NODETYPE>::~linked_list() {
       if (!IsEmpty()){
            //cout<<"Inside the deconstructor\n";
            current = first;
            while (current != NULL) {
                    //cout<<"Inside while loop\n";
                    first = first->next;
                    delete current;
                    current = first;
            }
            current = NULL;
            last = NULL;
            first = NULL;
       }
}
template <class NODETYPE>
linked_list<NODETYPE>::linked_list(linked_list<NODETYPE> &originalList) {
       if(originalList.first == nullptr){
           first = nullptr;
           last = nullptr;
       }else{
           ListNode<NODETYPE> *orig, *lastptr = nullptr;
           orig = originalList.first;
           lastptr = new ListNode<NODETYPE>;
           if(lastptr != nullptr){
               lastptr->data = orig->data;
               first = lastptr;
               orig = orig->next;
               while(orig!=nullptr){
                   current = lastptr;
                   lastptr = new ListNode<NODETYPE>(orig->data);
                   if(lastptr !=nullptr){
                       current->next = lastptr;
                   }
                   //current = current->next;
                   orig = orig->next;
               }
               last = lastptr;
           }
       }
}


template <class NODETYPE>
bool linked_list<NODETYPE>::InsertInOrder(NODETYPE value)
{
    ListNode<NODETYPE> * temp = nullptr;//Declare a new node
    temp = new ListNode<NODETYPE>; //New the node
    if(temp != nullptr){ //if the new node is not nullptr continue with the insert in order
        temp->data = value;
    
        if(first == NULL){//if this is the first node you are inserting the linked list
            InsertFront(value);
        } //call either insertFront or insertRear
        else if(temp->data < first->data){//else if the new node data is less than first data
            InsertFront(value);
        } //call insertFront
        else if(last->data < temp->data){//else if the new node data is greater than last data
            InsertRear(value);
        }
        //call insertRear
        else{//else
            current = first;//set current to first
            while(current != nullptr && current->next->data < value){//use a while loop to set current to the node before where you want to insert the new node
                current = current ->next;
                }
            temp->next = current->next; //connect the new node next to current next
            current->next = temp;//connect current next to the new node
            
        }
    }
    else{
        return false;
    }//else return false
    //return true
}


template <class NODETYPE>
bool linked_list<NODETYPE>::InsertFront(NODETYPE value) {
    ListNode<NODETYPE> * current = nullptr;
    current = new ListNode<NODETYPE>;
    if(current==nullptr){
        //cout<< "false" << endl;
        return false;
    }//if current equal nullptr return false
    else{//else
        current->data = value; //set current data to value
        //cout<< "current" << endl;
        if(first == NULL){//if this is the first node in the linked list
            first = current;//set first to current
            last = current;//set last to current
            current->next = nullptr;//set current next to nullptr
            //cout<< "Is null" << endl;
        }
        else{//else
           current->next = first; //set current next to first
           first = current; //set first to current
           //cout<< "Is not null" << endl;
        }
    return true;//return true;
    }
}

template <class NODETYPE>
bool linked_list<NODETYPE>::InsertRear(NODETYPE value) {
    ListNode<NODETYPE> * current = nullptr;
    current = new ListNode<NODETYPE>; //New a new node with current
    if(current==nullptr){
        return false;
    }//if current equal nullptr return false
    else{//else
        current->data = value; //set current data to value
        if(first == NULL){//if this is the first node in the linked list
            first = current;//set first to current
            last = current;//set last to current
            current->next = nullptr;//set current next to nullptr
        }
        else{//else
            last->next = current;//set last next to current
            current->next = nullptr;//set current next to nullptr
            last = current;//set last to current
        }
    return true;
    }

}

template <class NODETYPE>
bool linked_list<NODETYPE>::IsEmpty() const {
        return (first == NULL);
}

template <class NODETYPE>
bool linked_list<NODETYPE>::Search(NODETYPE value) {
        if(first == NULL){//if the list is empty return false
            return false;
        }
        else{//else
            current = first;//set current to first
            while(current !=nullptr && current->data != value){
                current = current -> next;
            }//use a while loop to check not for nullptr and not for current data not equal to the value
            if(current == nullptr){//if current equals null not found
                return false;//return false
            }
            else{//else
                return true;//return true
            }
        }
}


template <class NODETYPE>
void linked_list<NODETYPE>::PrintAll() {
    if(first != nullptr){//if not empty
        current = first;//set current to first
        while(current != nullptr){//use a while loop to check for not equal to nullptr
            cout << current->data << endl;//print out data
            current = current->next;//move current over
        }
    }
}

template <class NODETYPE>
bool linked_list<NODETYPE>::RemoveFront(NODETYPE & value) {
    if(first != nullptr){//else if the value equals the first data
        if(last == first){
            //cout<<"last == first\n";
            value = last -> data;
            delete first;
            current = NULL;
            last = NULL;
            first = NULL;
            //cout<<"End of just one\n";
            return true;
        }
        else{
            value = first -> data;//set value to first data
            current = first;//set current to first
            first = current -> next;//move first to the next node
            delete current;//delete current
            return true;
        }
    }//test
    return false;
}
template <class NODETYPE>
bool linked_list<NODETYPE>::RemoveRear(NODETYPE & value) {
    if(last != nullptr){//else if the value equals the last data
        if(last == first){
            //cout<<"last == first\n";
            value = last -> data;
            delete first;
            current = NULL;
            last = NULL;
            first = NULL;
            //cout<<"End of just one\n";
            return true;
        }
        else{
            //cout<<"More than 1\n";
            value = last-> data;//set value to last data
            current = first;//set current to first
            while(current->next != last){//use a while loop to set current to one before last
                current = current -> next;
            }
            delete last;//delete last
            last = current;//set last to current
            last->next = nullptr;
            current = nullptr;//set current next to nullptr
            return true;
        }
    }
        return false;
    }

template <class NODETYPE>
bool linked_list<NODETYPE>::Remove(NODETYPE & value) {
    if(first != nullptr && value == first -> data && last == first){//if the value equals the first data and it is the last node in the linked last
        value = first -> data;//set value to first data
        delete first;//remove the node and set current last and first to nullptr
        current = last = first = nullptr;
    }
    else if(first != nullptr && value == first->data){//else if the value equals the first data
        RemoveFront(value);
    }
    else if(first != nullptr && value == last -> data){//else if the value equals the last data
        RemoveRear(value);
        }
    else{//else
        current = first;//set current to first
        while(current != nullptr and current -> next -> data != value){//use a while loop to check for current does not equal null and current next data does not equal value
            current = current -> next;
        }
        if(current == nullptr){//if current equals null
            return false;//return false
        }
        else{ //else
            ListNode<NODETYPE> * temp = nullptr; //set temp pointer the node you will be deleting
            temp = new ListNode<NODETYPE>;
            temp = current->next;//set value to the temp data
            value = temp -> data;
            current -> next = temp -> next;//set current next to temp next
            delete temp;//delete temp
        }
        return true;//return true
    }
}

template <class NODETYPE>
linked_list<NODETYPE> & linked_list<NODETYPE>::operator=(const linked_list<NODETYPE> &origList){
       if(origList.first == nullptr){
           first = nullptr;
           last = nullptr;
       }else{
           ListNode<NODETYPE> *orig, *lastptr = nullptr;
           orig = origList.first;
           lastptr = new ListNode<NODETYPE>;
           if(lastptr != nullptr){
               lastptr->data = orig->data;
               first = lastptr;
               orig = orig->next;
               while(orig!=nullptr){
                   current = lastptr;
                   lastptr = new ListNode<NODETYPE>(orig->data);
                   if(lastptr !=nullptr){
                       current->next = lastptr;
                   }
                   //current = current->next;
                   orig = orig->next;
               }
               last = lastptr;
           }
       }
       return *this;
}

#endif