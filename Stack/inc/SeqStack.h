#ifndef SeqStack_H
#define SeqStack_H
#define STACKSIZE 1024
#include <cstring>
#include "common.h"

// 顺序栈存储结构声明
struct SeqStack{
	ElemType data[STACKSIZE];
	int top; // 初始化为0,指向栈顶下一个元素

	SeqStack(){ std::memset(this, 0, sizeof(SeqStack)); }
};

// 顺序栈基本操作
Status push( SeqStack& stk, ElemType x );
Status pop( SeqStack& stk );
ElemType top( SeqStack& stk );
bool empty( SeqStack& stk );

#endif