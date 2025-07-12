//
// Created by Henok on 9/17/2022.
//

#ifndef HW2_NODE_H
#define HW2_NODE_H
#include <iostream>

template<typename Object>
struct Node {
	Object data;
	struct Node* next;
	struct Node* prev;

	explicit Node(const Object& d = Object{ }, Node* p = nullptr, Node* n = nullptr) : data{ d }, prev{ p }, next{ n } { }
	explicit Node(Object&& d, Node* p = nullptr, Node* n = nullptr) : data{ std::move(d) }, prev{ p }, next{ n } { }
};

#endif //HW2_NODE_H
