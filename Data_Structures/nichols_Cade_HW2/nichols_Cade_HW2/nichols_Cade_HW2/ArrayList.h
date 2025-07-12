//
// Created by Henok on 9/19/2022.
//

#ifndef HW2_ARRAYLIST_H
#define HW2_ARRAYLIST_H


#include <algorithm>
#include <iostream>
#include <stdexcept>
#include "Exceptions.h"

// Forward declaration
template<class Object>
class ArrayList;

template<class Object>
ostream& operator<<(ostream& os, const ArrayList<Object>& l);

template <typename Object>
class ArrayList
{
public:
     explicit ArrayList(int initSize = 0) : _size{ initSize }, _capacity{ initSize + SPARE_CAPACITY }
     {
          _objects = new Object[_capacity];
     }

     ArrayList(const ArrayList& rhs)
          : _size{ rhs._size }, _capacity{ rhs._capacity }, _objects{ nullptr }
     {
          _objects = new Object[_capacity];
          for (int k = 0; k < _size; ++k)
               _objects[k] = rhs._objects[k];
     }

     ArrayList& operator= (const ArrayList& rhs)
     {
          ArrayList copy = rhs;
          std::swap(*this, copy);
          return *this;
     }

     ~ArrayList()
     {
          delete[] _objects;
     }

     ArrayList(ArrayList&& rhs) noexcept : _size{ rhs._size }, _capacity{ rhs._capacity }, _objects{ rhs._objects }
     {
          rhs._objects = nullptr;
          rhs._size = 0;
          rhs._capacity = 0;
     }

     ArrayList& operator= (ArrayList&& rhs) noexcept {
          std::swap(_size, rhs._size);
          std::swap(_capacity, rhs._capacity);
          std::swap(_objects, rhs._objects);

          return *this;
     }

     bool Empty() const
     {
          return Size() == 0;
     }
     int Size() const
     {
          return _size;
     }
     int Capacity() const
     {
          return _capacity;
     }

     Object& operator[](int index)
     {
#ifndef NO_CHECK
          if (index < 0 || index >= Size())
               throw ArrayIndexOutOfBoundsException{ };
#endif
          return _objects[index];
     }

     const Object& operator[](int index) const
     {
#ifndef NO_CHECK
          if (index < 0 || index >= Size())
               throw ArrayIndexOutOfBoundsException{ };
#endif
          return _objects[index];
     }

     void Resize(int newSize)
     {
          if (newSize > _capacity)
               Reserve(newSize * 2);
          _size = newSize;
     }

     void Reserve(int newCapacity)
     {
          if (newCapacity < _size)
               return;

          auto* newArray = new Object[newCapacity];
          for (int k = 0; k < _size; ++k)
               newArray[k] = std::move(_objects[k]);

          _capacity = newCapacity;
          std::swap(_objects, newArray);
          delete[] newArray;
     }

     void PushBack(const Object& x)
     {
          if (_size == _capacity)
               Reserve(2 * _capacity + 1);
          _objects[_size++] = x;
     }

     void PushBack(Object&& x)
     {
          if (_size == _capacity)
               Reserve(2 * _capacity + 1);
          _objects[_size++] = std::move(x);
     }

     void PopBack()
     {
          if (Empty())
               throw UnderflowException{ };
          --_size;
     }

     const Object& Back() const
     {
          if (Empty())
               throw UnderflowException{ };
          return _objects[_size - 1];
     }

     // Iterator stuff: not bounds checked
     typedef Object* Iterator;
     typedef const Object* ConstIterator;

     Iterator Begin()
     {
          return &_objects[0];
     }
     ConstIterator Begin() const
     {
          return &_objects[0];
     }
     Iterator End()
     {
          return &_objects[Size()];
     }
     ConstIterator End() const
     {
          return &_objects[Size()];
     }

     static const int SPARE_CAPACITY = 2;

     //1. Reverse the array
     void Reverse();


private:
     int _size;
     int _capacity;
     Object* _objects;

     friend ostream& operator<< <> (ostream& os, const ArrayList<Object>& l);
};


#endif //HW2_ARRAYLIST_H

template<typename Object>
ostream& operator<<(ostream& os, const ArrayList<Object>& l) {
     os << "Vector: [";
     for (auto it = l.Begin(); it != l.End(); ++it) {
          os << *it << ",";
     }
     os << "]";

     return os;
}

template<typename Object>
void ArrayList<Object>::Reverse() {
     std::reverse(this->Begin(), this->End());
}
