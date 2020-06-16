#include<iostream>
#include<assert.h>
#include "stack.h"

using namespace std;

template <class Type>
stack<Type>::stack()
{
    stackTop = NULL;
    size = 0;
}

template <class Type>
stack<Type>::~stack()
{
}

template <class Type>
Type stack<Type>::top() {
    assert(stackTop != NULL);
    return stackTop->data;
}

template <class Type>
void stack<Type>::display()
{
    node<Type> *cur = stackTop;
    cout << "Top --> ";
    while (cur != NULL)
    {
        /* code */
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
    cout << "Size is " << size << endl;
}

template <class Type>
bool stack<Type>::isEmpty() 
{
    return (stackTop == NULL);
}

template <class Type>
void stack<Type>::clear() 
{
    stackTop = NULL;
}

template <class Type>
void stack<Type>::push(Type item)
{
    node<Type> *newNode; // make a new node
    newNode = new node<Type>;
    newNode->data = item;
    newNode->next = stackTop; // make the new node 's next to the top
    stackTop = newNode;// the top is now the new node
    size++;
}

template <class Type>
void stack<Type>::pop()
{
    node<Type> *temp;
    if(!isEmpty()) {
        temp = stackTop;
        stackTop = stackTop->next;
        delete temp;
        size--;
    } else {
        cout << "Stack is empty!" << endl;
    }
}

template <class Type>
stack<Type> stack<Type>::operator=(stack<Type> & otherStack) 
{
    node<Type> *newNode;
    node<Type> *cur;
    node<Type> *last;
    if(stackTop != NULL) {
        stackTop = NULL;
    }
    if(otherStack.stackTop == NULL) {
        stackTop = NULL;
    }
    else {
        cur = otherStack.stackTop;
        stackTop = new node<Type>;
        stackTop->data = cur->data;
        stackTop->next = NULL;
        last = stackTop;
        cur = cur->next;
        while (cur != NULL)
        {
            newNode = new node<Type>;
            newNode->data = cur->data;
            newNode->next = NULL;
            last->next = newNode;
            last = newNode;
            cur = cur->next;
        }
    }
    size = otherStack.size;
    return *this;
}

