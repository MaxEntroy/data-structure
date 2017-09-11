#ifndef Queue_H
#define Queue_H
#define QUEUE_SIZE 1024
#include "common.h"
#include <cstring>

// ѭ�����нṹ����
struct Queue{
	ElemType data[QUEUE_SIZE];
	int front; // ͷָ��
	int rear;  // βָ��

	Queue(){ std::memset( this, 0, sizeof(Queue) ); }

};

// ѭ�����л�������
Status push( Queue& que, ElemType x );
Status pop( Queue& que );
ElemType front( Queue& que );
ElemType back( Queue& que );
int size( Queue& que );
bool empty( Queue& que );

#endif