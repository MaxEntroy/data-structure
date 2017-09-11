#include "Queue.h"
#include <iostream>

Status push( Queue& que, ElemType x ){
	if( (que.rear + 1)%QUEUE_SIZE == que.front ){
		std::cerr << "Overflow";
		return OVERFLOW;
	}
	else{
		que.data[ que.rear ] = x;
		que.rear = ( que.rear + 1 )%QUEUE_SIZE;
		return OK;
	} 
}
Status pop( Queue& que ){
	if( que.front == que.rear ){
		std::cerr << "Underflow";
		return UNDERFLOW;
	}
	else{
		que.front = (que.front + 1)%QUEUE_SIZE;
		return OK;
	}
}
ElemType front( Queue& que ){
	if( que.front == que.rear ){
		std::cerr << "Underflow";
		return UNDERFLOW;
	}
	else{
		return que.data[que.front];
	}
}
ElemType back( Queue& que ){
	if( que.front == que.rear ){
		std::cerr << "Underflow";
		return UNDERFLOW;
	}
	else{
		return que.data[ (que.rear - 1)%QUEUE_SIZE ];
	}
}
int size( Queue& que ){
	return (que.rear - que.front + QUEUE_SIZE)%QUEUE_SIZE;
}
bool empty( Queue& que ){
	return que.front == que.rear;
}