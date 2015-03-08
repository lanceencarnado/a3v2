#ifndef QUEUE_H
#define QUEUE_H

#include "Pirate.h"

class Queue
{
    class Node 
    {
        friend class Queue;
        private:
            Pirate* data;
            Node*   next;
            Node*   prev;
    };
    
    public:
        Queue();
        Queue(Queue&);
        ~Queue();
        int push(Pirate*);
        int pop();
        int tempPop();
        Pirate* front();
        bool empty();
        bool contains(int);
        int remove(int);
		void deleteData();
    private:
        Node* head;
};

#endif
