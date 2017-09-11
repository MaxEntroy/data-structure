#ifndef LinkedStack_H
#define LinkedStack_H
#include "common.h"
#include <cstdlib>

/* ��ջ�ڵ����� */
struct ListNode
{
	ElemType data;
	ListNode* next;

	ListNode() : data(0), next(NULL) {}
	ListNode( ElemType x ) : data(x), next(NULL) {}
};

typedef ListNode* LinkedStack; // LinkedStack��ָ��ListNode���͵�ָ��

// ��ջ��������
Status push( LinkedStack& top, ElemType x );
Status pop( LinkedStack& top );
ElemType top( LinkedStack& top );
bool empty( LinkedStack& top );

#endif