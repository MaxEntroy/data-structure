#ifndef LinkedStack_H
#define LinkedStack_H
#include "common.h"
#include <cstdlib>

/* 链栈节点声明 */
struct ListNode
{
	ElemType data;
	ListNode* next;

	ListNode() : data(0), next(NULL) {}
	ListNode( ElemType x ) : data(x), next(NULL) {}
};

typedef ListNode* LinkedStack; // LinkedStack是指向ListNode类型的指针

// 链栈基本操作
Status push( LinkedStack& top, ElemType x );
Status pop( LinkedStack& top );
ElemType top( LinkedStack& top );
bool empty( LinkedStack& top );

#endif