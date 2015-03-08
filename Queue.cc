//
//  Queue.cc
//  
//
//  Created by Angus Leung on 2015-03-07.
//
//


#include "Queue.h"


//Default constructor
Queue::Queue() : head(0){
    
    
}

//Copy constructor
Queue::Queue(Queue &origQueue) {
	head = 0;
	Node *origCurrNode;
	
	origCurrNode = origQueue.head;
	
	while (origCurrNode != 0) {
		push(origCurrNode->data);
		origCurrNode = origCurrNode->next;
	}
}

//Destructor
Queue::~Queue() {
    Node *currNode, *nextNode;

    currNode = head;

    while (currNode != 0) {
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }
}

int Queue::push(Pirate* newPirate) {
    Node *newNode;
    Node *currNode, *prevNode;

    newNode = new Node;
    newNode->data = newPirate;
    newNode->prev = 0;
    newNode->next = 0;

    prevNode = 0;
    currNode = head;

    while (currNode != 0) {
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (prevNode == 0) {
        head = newNode;
    }
    else {
        prevNode->next = newNode;
        newNode->prev  = prevNode; 
    } 

    newNode->next = currNode;

    if (currNode != 0) {
        currNode->prev = newNode;
    }
    
    return C_OK;
}

int Queue::pop() {
    if (head != 0)
        return remove(head->data->getId());
    else 
        return C_NOK;
}

// A pop function that does not delete the removed Node's data
// (required for the tempQueue that is made in the printBrig function)

int Queue::tempPop() {
	if (head == 0)
		return C_NOK;
	Node* newHead = head->next;
	delete head;
	head = newHead;
	if (head != 0)
		head->prev = 0;
	return C_OK;
}

Pirate* Queue::front() {
    return head->data;
}

bool Queue::empty() {
    if (head == 0)
        return true;
    else 
        return false;   
}

int Queue::remove(int pirateId) {
    Node *currNode, *prevNode;

    prevNode = 0;
    currNode = head;

    while (currNode != 0) {
        if (currNode->data->getId() == pirateId)
            break;
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode == 0)
        return C_NOK;

    if (prevNode == 0) {        // first position
        head = currNode->next;
        if (head != 0)          // if there is a head already
            head->prev = 0;     // set the head's prev to null
    }
    else {                      // middle or end position
        prevNode->next = currNode->next;
        if (currNode->next != 0)
            currNode->next->prev = prevNode;
    }

    delete currNode->data;
    delete currNode;
    
    return C_OK;

}


bool Queue::contains(int pirateId) {
    Node *currNode;
    
    currNode = head;
    
    while (currNode != 0) {
        if (currNode->data->getId() == pirateId)
            return true;
        currNode = currNode->next;
    }
    
    return false;   // we broke out of the while loop because currNode == 0, so it's not there
}

// Deletes the data contained in every Node - can't be put in the destructor
// because the tempQueue in printBrig calls the destructor
void Queue::deleteData() {
    Node *currNode, *nextNode;

    currNode = head;

    while (currNode != 0) {
        nextNode = currNode->next;
        delete currNode->data;
        currNode = nextNode;
    }
}

