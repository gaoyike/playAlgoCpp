#include <iostream>
#include <assert.h>
#include "queue.h"

using namespace std;

template <class Type>
queue<Type>::queue()
{
    size = 0;
    queueFront = NULL;
    queueRear = NULL;
}

template <class Type>
queue<Type>::~queue()
{
}

template <class Type>
void queue<Type>::display() 
{
    node<Type> *cur = queueFront;
    while (cur != NULL)
    {
        cout << cur->data << "  ";
        cur = cur->next;
    }
    cout << endl;
    cout << "Size  = " << size << endl;    
}

template <class Type>
bool queue<Type>::isEmpty() 
{
    return (queueFront == NULL);
}

template <class Type>
void queue<Type>::clear() 
{
    queueFront = NULL;
}

template <class Type>
void queue<Type>::enQueue(Type item)
{
    node<Type> *newNode;
    newNode = new node<Type>;
    newNode->data = item;
    newNode->next = NULL;
    if (queueFront == NULL)
    {
        queueFront = newNode;
        queueRear = newNode;
    }
    else
    {
        queueRear->next = newNode;
        queueRear = queueRear->next;
    }
    size++;
}

template <class Type>
Type queue<Type>::front()
{
    assert(queueFront != NULL);
    return queueFront->data;
}

template <class Type>
void queue<Type>::deQueue()
{
    node<Type> *item;
    if (!isEmpty())
    {
        item = queueFront;
        queueFront = queueFront->next;
        delete item;
        size--;
    }
    else
    {
        cout << "queue is empty" << endl;
    }
}
