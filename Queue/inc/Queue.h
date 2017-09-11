#ifndef Queue_H
#define Queue_H
#define QUEUE_SIZE 1024
#include "common.h"
#include <cstring>

// 循环队列结构定义
struct Queue{
	ElemType data[QUEUE_SIZE];
	int front; // 头指针
	int rear;  // 尾指针

	Queue(){ std::memset( this, 0, sizeof(Queue) ); }

};

// 循环队列基本操作
Status push( Queue& que, ElemType x );
Status pop( Queue& que );
ElemType front( Queue& que );
ElemType back( Queue& que );
int size( Queue& que );
bool empty( Queue& que );

#endif