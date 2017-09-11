#ifndef BiTree_H
#define BiTree_H
#include <cstring>
#include "common.h"

// 二叉树节点结构声明
struct BiNode{
	ElemType data;
	BiNode* left;
	BiNode* right;

	BiNode(){ std::memset(this, 0, sizeof(BiNode)); }
	BiNode( ElemType x ) : data(x), left(NULL), right(NULL){}
};

typedef BiNode* BiTree; // BiTree是指向BiNode类型的指针
typedef Status (*callback)(BiTree) ; // 定义函数指针

// 后根遍历辅助数据结构
struct Element{
	BiTree ptr;
	int flag;
	Element(){ std::memset(this, 0, sizeof(Element));}
	Element( BiTree p, int flg ) : ptr(p), flag(flg) {}
};

// 二叉树基本操作声明
BiTree create_bitree( const ElemType* arr, int cur );

Status pre_order( BiTree root,  callback visit);
Status pre_order_without_recursion( BiTree root, callback visit );
Status in_order( BiTree root, callback visit );
Status in_order_without_recursion( BiTree root, callback visit );
Status post_order( BiTree root, callback visit );
Status post_order_without_recursion( BiTree root, callback visit );
Status level_order( BiTree root, callback visit );

#endif