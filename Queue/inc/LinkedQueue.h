#ifndef LinkedQueue_H
#define LinkedQueue_H
#include "common.h"
#include <cstdlib>
#include <cstring>

// �����нڵ�ṹ����
struct ListNode{
	ElemType data;
	ListNode* next;

	ListNode() { std::memset(this, 0, sizeof(ListNode)); }
	ListNode( ElemType x ) : data(x), next(NULL) {}

};

// �����нṹ����
struct LinkedQueue{
	ListNode* front; // frontָ�����ǰһ��Ԫ�ؼ�ͷ���
	ListNode* rear;  // rearָ���βԪ��

	LinkedQueue(){
		front = new ListNode; // ����ͷ���
		rear = front;
	}
	virtual ~LinkedQueue(){
		delete front;
	}
};

// �����л�������
Status push( LinkedQueue& que, ElemType x );
Status pop( LinkedQueue& que );
ElemType front( LinkedQueue& que );
ElemType back( LinkedQueue& que );
int size( LinkedQueue& que );
bool empty( LinkedQueue& que );

#endif