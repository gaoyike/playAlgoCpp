#ifndef STACK_H
#define STACK_H

template <class Type>
struct node
{
    Type data;
    node<Type> *next;
    /* data */
};

template <class Type>
class stack 
{
    public:
        void display();
        stack();
        ~stack();
        bool isEmpty();
        void push(Type item);
        Type top();
        void pop();
        void clear();

        stack<Type> operator=(stack<Type> & otherStack);


    private:
        node<Type> *stackTop;
        int size;
};
#endif 