#ifndef STACK_H
#define STACK_H

class Stack {
private:
    int* arr;       
    int top;        
    int capacity;   

public:
    
    Stack(int size);

    
    void push(int value);

    
    int pop();

    
    int peek();

    
    bool isEmpty();

    
    bool isFull();

    
    ~Stack();
};

#endif