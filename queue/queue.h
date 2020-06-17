#ifndef QUEUE_H
#define QUEUE_H

template <class Type>
struct node
{
    Type data;
    node<Type> *next;
};

template <class Type>
class queue
{
    public:
        void display();
        queue();
        ~queue();
        bool isEmpty();
        void enQueue(Type item);
        Type front();
        void deQueue();
        void clear();
    private:
        int size;
        node<Type> *queueFront;
        node<Type> *queueRear;
};

#endif