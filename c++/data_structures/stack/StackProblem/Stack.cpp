#include <iostream>
#include "Stack.h"
using namespace std;

Stack::Stack(int size) {
    capacity = size;
    arr = new int[capacity];
    top = -1;
}

void Stack::push(int value) {
    if (top == capacity - 1) {
        cout << "Stack Overflow!\n";
        return;
    }
    arr[++top] = value;
    cout << value << " pushed.\n";
}

int Stack::pop() {
    if (top == -1) {
        cout << "Stack Underflow!\n";
        return -1;
    }
    return arr[top--];
}

int Stack::peek() {
    if (top == -1) {
        cout << "Stack is empty!\n";
        return -1;
    }
    return arr[top];
}

bool Stack::isEmpty() {
    return top == -1;
}

bool Stack::isFull() {
    return top == capacity - 1;
}

Stack::~Stack() {
    delete[] arr;
}
