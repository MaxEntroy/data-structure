#include "LinkedStack.h"
#include <iostream>

// ��ջ��������
Status push( LinkedStack& top, ElemType x ){
	LinkedStack cur = new ListNode(x);
	if(!cur){
		std::cerr << "Not enough space!";
		return ERROR;
	}

	if(!top) top = cur;
	else{
		cur->next = top;
		top = cur; // topһֱָ��ͷָ���λ��
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