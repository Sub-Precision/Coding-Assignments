//
// Created by Henok on 9/22/2022.
//

#ifndef HW2_ALGORITHMS_H
#define HW2_ALGORITHMS_H

#include "LinkedList.h"
#include "ArrayList.h"

/*1.A.
 * Reverse Algorithm – is an algorithm that puts the elements of the
 * array in reverse order. Implement a reverse method to reverse elements
 * of an array list. Discuss your implementation and complexity of this
 * algorithm in your ReadMe File.
 * NOTE: Calling std::reverse method doesn't count as a solution.
 * */

template<class T>
void Reverse(ArrayList<T>& array) {
     auto start = array.Begin();
     auto end = array.End();

     while (start != end && start != --end)
     {
          std::iter_swap(start, end);
          start++;
     }
}

/*
 * 1.B.	Sorting Algorithm - Bubble Sort functions by creating a sequence of
 * pairwise comparisons of adjacent elements from an array. Beginning with
 * the leftmost two integers from an array of size n of distinct integers,
 * the algorithm compares the two numbers. If the left entry is larger than
 * the right entry, the integers swap positions. If the left entry is smaller
 * than the right entry, the two remain in position, and the algorithm continues.
 * Next, Bubble Sort compares the (possibly just changed) second entry and the
 * third entry from the array and makes the comparison step again. Once all
 * adjacent elements have been compared pairwise and necessary swaps have been
 * completed, a full pass of the algorithm is complete. In general, the algorithm
 * will require a maximum of n − 1 passes to entirely sort the array. Implement a
 * Bubble Sort algorithm that sorts a ListArray of any data type. Discuss the
 * complexity of this algorithm.
 */

 //Bubble sort helper function
template<class T>
void Swap(T& a, T& b) {
     T tmp = std::move(a);
     a = std::move(b);
     b = std::move(tmp);
};

template<class T>
void BubbleSort(ArrayList<T>& array) {
     int i, j;
     auto n = array.Size();
     for (i = 0; i < n - 1; i++) {
          // Last i elements are already in place
          for (j = 0; j < n - i - 1; j++) {
               if (array[j] > array[j + 1])
                    Swap(array[j], array[j + 1]);
          }
     }
}

template<class T>
void Reverse(LinkedList<T>& array) {
     auto start = array.Begin();
     auto end = array.End();

     while (start != end && start != --end)
     {
          std::iter_swap(start, end);
          start++;
     }
}

template<class T>
void BubbleSort(LinkedList<T>& array) {
     auto m = array.Size();
     for (auto i = array.Begin(); i != array.End(); i++)
     {
          for (auto j = array.Begin(); j != i; j++)
          {
               if (*i < *j)
               {
                    std::iter_swap(i, j);
               }
          }
     }
}

/*
 * 	Implement the STL find routine that returns the iterator
 * 	containing the first occurrence of x in the range that begins
 * 	at start and extends up to but not including end. If x is not
 * 	found, end is returned. This method should work for both Container
 * 	classes. Discuss its complexity.
 * */

template <typename Iterator, typename Object>
Iterator Find(Iterator start, Iterator end, const Object& x)
{
     while (start != end)
     {
          if (*start == x)
               return start;
          ++start;
     }
     return end;
}



#endif //HW2_ALGORITHMS_H
