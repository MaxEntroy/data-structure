#ifndef SeqStack_H
#define SeqStack_H
#define STACKSIZE 1024
#include <cstring>
#include "common.h"

// ˳��ջ�洢�ṹ����
struct SeqStack{
	ElemType data[STACKSIZE];
	int top; // ��ʼ��Ϊ0,ָ��ջ����һ��Ԫ��

	SeqStack(){ std::memset(this, 0, sizeof(SeqStack)); }
};

// ˳��ջ��������
Status push( SeqStack& stk, ElemType x );
Status pop( SeqStack& stk );
ElemType top( SeqStack& stk );
bool empty( SeqStack& stk );

#endif