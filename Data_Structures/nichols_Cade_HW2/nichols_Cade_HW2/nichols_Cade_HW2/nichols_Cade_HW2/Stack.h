//
// Created by Henok on 9/22/2022.
//

#ifndef HW2_STACK_H
#define HW2_STACK_H
#include <iostream>

template<class ContainerType, class DataType>
class Stack;

template<class ContainerType, class DataType>
std::ostream& operator<<(std::ostream& os, const Stack<ContainerType, DataType>& l);

template<class ContainerType, class DataType>
class Stack {
     int _size{};
     ContainerType _stack;
     int _top{};

     friend std::ostream& operator<< <> (std::ostream& os, const Stack<ContainerType, DataType>& l);
public:
     explicit Stack(int size)
     {
          this->_size = size;
          this->_stack.Reserve(this->_size);
          this->_top = -1;
     }

     void Push(const DataType& element); // Pushes element on to stack
     void Pop(); // Pops top element and updates top

     bool IsEmpty() { return (this->_top == -1); }
     bool IsFull() { return (this->_top == this->_size - 1); }
     DataType Peek() { return this->_stack[_top]; }
};

#endif //HW2_STACK_H

template<class ContainerType, class T>
void Stack<ContainerType, T>::Push(const T& element) {
     _stack.PushBack(element);
     ++_top;
}

template<class ContainerType, class T>
void Stack<ContainerType, T>::Pop() {
     if (IsEmpty())
          return;
     _stack[_top--];
     _size--;
}

template<class ContainerType, class T>
std::ostream& operator<<(std::ostream& os, const Stack<ContainerType, T>& l) {
     os << "Stack: (";
     for (int i = 0; i < l._size; ++i) {
          os << l._stack[i] << ",";
     }
     os << ")\n";

     return os;
}
