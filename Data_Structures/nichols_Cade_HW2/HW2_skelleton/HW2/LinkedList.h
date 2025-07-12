////
//// Created by Henok on 9/17/2022.
////
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <algorithm>
#include "Node.h"

using namespace std;


template<class Object>
class LinkedList;

template<class Object>
ostream& operator<<(ostream& os, const LinkedList<Object>& l);

template <typename Object>
class LinkedList
{

public:
    class ConstIterator
    {
    public:

        // Public constructor for ConstIterator.
        ConstIterator( ) : current{nullptr }
        { }

        virtual // Return the object stored at the current position.
        // For ConstIterator, this is an accessor with a
        // const reference return type.
        const Object & operator* ( ) const
        { return retrieve( ); }

        virtual ConstIterator & operator++ ( )
        {
            current = current->next;
            return *this;
        }

        ConstIterator operator++ (int )
        {
            ConstIterator old = *this;
            ++( *this );
            return old;
        }

        ConstIterator & operator-- ( )
        {
            current = current->prev;
            return *this;
        }

        ConstIterator operator-- (int )
        {
            ConstIterator old = *this;
            --( *this );
            return old;
        }

        bool operator== ( const ConstIterator & rhs ) const
        { return current == rhs.current; }

        bool operator!= ( const ConstIterator & rhs ) const
        { return !( *this == rhs ); }

    protected:
        Node<Object> *current;

        // Protected helper in ConstIterator that returns the object
        // stored at the current position. Can be called by all
        // three versions of operator* without any type conversions.
        Object & retrieve( ) const
        { return current->data; }

        // Protected constructor for ConstIterator.
        // Expects a pointer that represents the current position.
        explicit ConstIterator(Node<Object> *p ) : current{p }
        { }

        friend class LinkedList<Object>;
    };

    class Iterator : public ConstIterator
    {
    public:

        // Public constructor for Iterator.
        // Calls the base-class constructor.
        // Must be provided because the private constructor
        // is written; otherwise zero-parameter constructor
        // would be disabled.
        Iterator( ) = default;

        Object & operator* ( )
        { return ConstIterator::retrieve( ); }

        // Return the object stored at the current position.
        // For Iterator, there is an accessor with a
        // const reference return type and a mutator with
        // a reference return type. The accessor is shown first.
        const Object & operator* ( ) const
        { return ConstIterator::operator*( ); }

        Iterator & operator++ ( )
        {
            this->current = this->current->next;
            return *this;
        }

        Iterator operator++ (int )
        {
            Iterator old = *this;
            ++( *this );
            return old;
        }

        Iterator & operator-- ( )
        {
            this->current = this->current->prev;
            return *this;
        }

        Iterator operator-- (int )
        {
            Iterator old = *this;
            --( *this );
            return old;
        }

        /*
         * 	Looking ahead in an STL iterator requires an application of
         * 	operator++, which in turn advances the iterator. Operator -
         * 	- performs a similar operation in opposite direction. In some
         * 	cases, looking at the next or previous item in the list, without
         * 	advancing to it, may be preferable. Write LinkedList member
         * 	functions with the declaration ConstIterator operator+( int k )
         * 	const; and ConstIterator operator-( int k ) const; to facilitate
         * 	this in a general case. The binary operator+ returns an iterator
         * 	that corresponds to k positions ahead of current and the binary
         * 	operator- returns an iterator that corresponds to k position before
         * 	the current.
         *
         *
         */
       ConstIterator operator+ ( int k){


            return *this;
        }

        ConstIterator operator- ( int k){


            return *this;
        }
    protected:
        // Protected constructor for Iterator.
        // Expects the current position.
        Iterator(Node<Object> *p ) : ConstIterator{p }
        { }

        friend class LinkedList<Object>;
    };

public:
    LinkedList( ) { init( ); }

    ~LinkedList( )
    {
        clear( );
        delete _head;
        delete _tail;
    }

    LinkedList(const LinkedList & rhs )
    {
        init( );
        for( auto & x : rhs )
            PushBack(x);
    }

    LinkedList & operator= (const LinkedList & rhs )
    {
        LinkedList copy = rhs;
        std::swap( *this, copy );
        return *this;
    }


    LinkedList(LinkedList && rhs ) noexcept : _size{rhs._size }, _head{rhs._head }, _tail{rhs._tail }
    {
        rhs._size = 0;
        rhs._head = nullptr;
        rhs._tail = nullptr;
    }

    LinkedList & operator= (LinkedList && rhs )
    {
        std::swap(_size, rhs._size );
        std::swap(_head, rhs._head );
        std::swap(_tail, rhs._tail );

        return *this;
    }

    // Return Iterator representing beginning of list.
    // Mutator version is first, then accessor version.
    Iterator Begin( )
    { return Iterator(_head->next ); }

    ConstIterator Begin( ) const
    { return ConstIterator(_head->next ); }

    // Return Iterator representing endmarker of list.
    // Mutator version is first, then accessor version.
    Iterator End( )
    { return Iterator(_tail ); }

    ConstIterator End( ) const
    { return ConstIterator(_tail ); }

    // Return number of elements currently in the list.
    int Size( ) const
    { return _size; }

    // Return true if the list is Empty, false otherwise.
    bool Empty( ) const
    { return Size() == 0; }

    void clear( )
    {
        while( !Empty() )
            PopFront();
    }

    // Front, Back, PushFront, PushBack, PopFront, and PopBack
    // are the basic double-ended queue operations.
    Object & Front( )
    { return *Begin(); }

    const Object & Front( ) const
    { return *Begin(); }

    Object & Back( )
    { return *--End(); }

    const Object & back( ) const
    { return *--End(); }

    void PushFront(const Object & x )
    { Insert(Begin(), x); }

    void PushBack(const Object & x )
    { Insert(End(), x); }

    void PushFront(Object && x )
    { Insert(Begin(), std::move(x)); }

    void PushBack(Object && x )
    { Insert(End(), std::move(x)); }

    void PopFront( )
    { Erase(Begin()); }

    void PopBack( )
    { Erase(--End()); }

    // Insert x before itr.
    Iterator Insert(Iterator itr, const Object & x )
    {
        Node<Object> *p = itr.current;
        ++_size;
        return Iterator(p->prev = p->prev->next = new Node<Object>{x, p->prev, p } );
    }

    // Insert x before itr.
    Iterator Insert(Iterator itr, Object && x )
    {
        Node<Object> *p = itr.current;
        ++_size;
        return Iterator(p->prev = p->prev->next = new Node<Object>{std::move(x ), p->prev, p } );
    }

    // Erase item at itr.
    Iterator Erase(Iterator itr )
    {
        Node<Object> *p = itr.current;
        Iterator retVal(p->next );
        p->prev->next = p->next;
        p->next->prev = p->prev;

        delete p;
        --_size;

        return retVal;
    }

    Iterator Erase(Iterator from, Iterator to )
    {
        for(Iterator itr = from; itr != to; )
            itr = Erase(itr);

        return to;
    }

private:
    int  _size{};
    Node<Object> *_head;
    Node<Object> *_tail;

    void init( )
    {
        _size = 0;
        _head = new Node<Object>;
        _tail = new Node<Object>;
        _head->next = _tail;
        _tail->prev = _head;
    }

    friend ostream& operator<< <> (ostream& os, const LinkedList<Object>& l);
};

#endif


template<typename Object>
ostream &operator<<(ostream &os, const LinkedList<Object> &l) {

    for (auto it = l.Begin(); it != l.End(); ++it){
        os <<"|"<<*it<<"|<-->";
    }
    os<<"NULL";

    return os;
}