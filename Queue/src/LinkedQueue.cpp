#include <iostream>
#include "LinkedQueue.h"
Status push( LinkedQueue& que, ElemType x ){
	ListNode* s = new ListNode(x);
	if(!s){
		std::cerr << "Not enough space!";
		return ERROR;
	}
	que.rear->next = s;
	que.rear = s;
	return OK;
}
Status pop( LinkedQueue& que ){
	ListNode* s = que.front->next;
	if(!s){
		std::cerr << "Underflow";
		return UNDERFLOW;
	}
	else{
		que.front->next = s->next;
		delete s;

		return OK;
	}
	
}
ElemType front( LinkedQueue& que ){
	ListNode* s = que.front->next;
	if(!s){
		std::cerr << "Underflow";
		return UNDERFLOW;
	}
	else{
		return s->data;
	}
}
ElemType back( LinkedQueue& que ){
	ListNode* s = que.rear;
	if(!s){
		std::cerr << "Underflow";
		return UNDERFLOW;
	}
	else{
		return s->data;
	}
}
int size( LinkedQueue& que ){
	ListNode* p = que.front->next;
	int cnt = 0;
	while(p){
		++cnt;
		p = p->next;
	}
	return cnt;
}
bool empty( LinkedQueue& que ){
	return que.front == que.rear;
}