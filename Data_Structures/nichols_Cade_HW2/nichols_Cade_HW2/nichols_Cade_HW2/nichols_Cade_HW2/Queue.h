//
// Created by Henok on 9/22/2022.
//

#ifndef HW2_QUEUE_H
#define HW2_QUEUE_H

#include <iostream>

template<class ContainerType, class DataType>
class Deque;

template<class ContainerType, class DataType>
std::ostream& operator<<(std::ostream& os, const Deque<ContainerType, DataType>& l);

template<class ContainerType, class DataType>
class Deque {
     int _size{};
     DataType _front;
     DataType _rear;
     ContainerType _deque;

     friend std::ostream& operator<< <> (std::ostream& os, const Deque<ContainerType, DataType>& l);
public:
     explicit Deque() {
          this->_size = 0;
     }

     void Push(const DataType& element); // Insert item x on the front end of the deque.
     DataType Pop(); // Remove the front item from the front end of deque and return it.
     void Inject(const DataType& element); //Insert item on the rear end of the deque.
     DataType Eject(); //Remove the rear item from the deque and return it.

};

template<class ContainerType, class DataType>
void Deque<ContainerType, DataType>::Push(const DataType& element) {
     _deque.PushFront(element);
     _front = *(_deque.Begin());
     _size++;
     if (_size == 1)
     {
          _rear = _front;
     }
}

template<class ContainerType, class DataType>
DataType Deque<ContainerType, DataType>::Pop() {
     _deque.PopFront();
     _size--;
     _front = *(_deque.Begin()++);
     return _front;
}

template<class ContainerType, class DataType>
void Deque<ContainerType, DataType>::Inject(const DataType& element) {
     _deque.PushBack(element);
     this->_rear = *(_deque.End()-1);
     _size++;
}

template<class ContainerType, class DataType>
DataType Deque<ContainerType, DataType>::Eject() {
     _deque.PopBack();
     _size--;
     this->_rear = *(_deque.End()-1);
     return _rear;
}

template<class ContainerType, class T>
std::ostream& operator<<(std::ostream& os, const Deque<ContainerType, T>& l) {
     os << "Deque:" << l._deque << endl;
     os << "Front: " << l._front << " Rear: " << l._rear << std::endl;
     return os;
}

#endif //HW2_QUEUE_H
