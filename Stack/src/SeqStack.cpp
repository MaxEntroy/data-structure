#include "SeqStack.h"
#include "common.h"
#include <iostream>

// Ë³ÐòÕ»»ù±¾²Ù×÷
Status push( SeqStack& stk, ElemType x ){
	if( STACKSIZE == stk.top ){
		std::cerr << "Stack Overflow";
		return OVERFLOW;
	}

	stk.data[stk.top++] = x;

	return OK;
}
Status pop( SeqStack& stk ){
	if( !stk.top ){
		std::cerr << "Stack Underflow";
		return UNDERFLOW;
	}
	stk.top--;
	return OK;
}
ElemType top( SeqStack& stk ){
	if( empty(stk) ){
		std::cerr << "Stack is empty!";
		return ERROR;
	}
	return stk.data[stk.top-1];
}
bool empty( SeqStack& stk ){
	return !stk.top;
}