#include <iostream>
#include "Algorithms.h"
#include "Stack.h"
#include <assert.h>
#include "Queue.h"

int main() {
    // LinkedList test program
    std::cout<<"--------------Linked List---------------------------\n";
    LinkedList<int> intList;

    intList.PushFront(-11);
    intList.PushFront(2);
    intList.PushFront(1);
    std::cout<<"1. Operation: PushFront(-11, 2, 1)\n";
    std::cout<<"LinkedList: " <<intList<<std::endl;
    intList.PushBack(10);
    intList.PushBack(4);
    intList.PushBack(5);
    std::cout<<"2. Operation: PushBack(10, 4, 5)\n";
    std::cout<<"LinkedList: " <<intList<<std::endl;
    intList.PopFront();
    std::cout<<"3. Operation: PopFront()\n";
    std::cout<<"LinkedList: "<<intList<<std::endl;
    intList.PopBack();
    std::cout<<"4. Operation: PopBack()\n";
    std::cout<<"LinkedList: "<<intList<<std::endl;
    std::cout<<"4. Operation: Find(10)\n";
//    auto findItem = 10;
//    auto found = Find(intList.Begin(), intList.End(), findItem);
//    assert(findItem == *found);
//    assert ( findItem == *(intList.Begin() + 2 ));


    std::cout<<"--------------Array List (Vector)---------------------------\n";
    ArrayList<int> intArray;
    intArray.PushBack(-11);
    intArray.PushBack(2);
    intArray.PushBack(1);
    intArray.PushBack(5);
    intArray.PushBack(8);
    std::cout<<"1. Operation: PushBack(-11, 2, 1, 5, 8)\n";
    std:cout<<intArray<<endl;
    intArray.PopBack();
    std::cout<<"2. Operation: PopBack()\n";
    std::cout<<intArray<<std::endl;
    std::cout<<"2. Operation: Reverse()\n";
    Reverse(intArray);
    std::cout<<intArray<<std::endl;
    std::cout<<"3. Operation: BubbleSort()\n";
    BubbleSort(intArray);
    std::cout<<intArray<<std::endl;
    auto itemToFind = 2;
    assert(itemToFind = *Find(intArray.Begin(), intArray.End(), itemToFind));


    std::cout<<"--------------Stacks---------------------------\n";
    Stack<ArrayList<int>, int> intStack(5);
    intStack.Push(4);
    intStack.Push(3);
    intStack.Push(1);
    intStack.Push(-3);
    intStack.Push(8);
    std::cout<<"1. Operation: PushBack(4, 3, 1, -3, 8)\n";
    std::cout<<intStack;
    std::cout<<"2. Operation: Pop()\n";
    intStack.Pop();
    std::cout<<intStack<<endl;

    std::cout<<"--------------Deque---------------------------\n";
    Deque<LinkedList<int>, int> deque;
    deque.Push(10);
    deque.Push(3);
    deque.Push(2);
    std::cout<<deque;
    deque.Inject(-3);
    std::cout<<deque;
    deque.Eject();
    std::cout<<deque;
    deque.Pop();
    std::cout<<deque;
    return 0;
}
