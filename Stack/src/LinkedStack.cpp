#include "LinkedStack.h"
#include <iostream>

// 链栈基本操作
Status push( LinkedStack& top, ElemType x ){
	LinkedStack cur = new ListNode(x);
	if(!cur){
		std::cerr << "Not enough space!";
		return ERROR;
	}

	if(!top) top = cur;
	else{
		cur->next = top;
		top = cur; // top一直指向头指针的位置
	}

	return OK;
}
Status pop( LinkedStack& top ){
	if(!top){
		std::cerr << "Stack Underflow";
		return UNDERFLOW;
	}
	LinkedStack nex = top->next;
	delete top;
	top = nex;

	return OK;
}
ElemType top( LinkedStack& top ){
	if(!top){
		std::cerr << "Stack Underflow";
		return UNDERFLOW;
	}
	return top->data;
}
bool empty( LinkedStack& top ){
	return !top;
}