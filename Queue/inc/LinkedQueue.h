#ifndef LinkedQueue_H
#define LinkedQueue_H
#include "common.h"
#include <cstdlib>
#include <cstring>

// 链队列节点结构声明
struct ListNode{
	ElemType data;
	ListNode* next;

	ListNode() { std::memset(this, 0, sizeof(ListNode)); }
	ListNode( ElemType x ) : data(x), next(NULL) {}

};

// 链队列结构声明
struct LinkedQueue{
	ListNode* front; // front指向队首前一个元素即头结点
	ListNode* rear;  // rear指向队尾元素

	LinkedQueue(){
		front = new ListNode; // 增加头结点
		rear = front;
	}
	virtual ~LinkedQueue(){
		delete front;
	}
};

// 链队列基本操作
Status push( LinkedQueue& que, ElemType x );
Status pop( LinkedQueue& que );
ElemType front( LinkedQueue& que );
ElemType back( LinkedQueue& que );
int size( LinkedQueue& que );
bool empty( LinkedQueue& que );

#endif