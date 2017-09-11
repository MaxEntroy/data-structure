#ifndef BiTree_H
#define BiTree_H
#include <cstring>
#include "common.h"

// �������ڵ�ṹ����
struct BiNode{
	ElemType data;
	BiNode* left;
	BiNode* right;

	BiNode(){ std::memset(this, 0, sizeof(BiNode)); }
	BiNode( ElemType x ) : data(x), left(NULL), right(NULL){}
};

typedef BiNode* BiTree; // BiTree��ָ��BiNode���͵�ָ��
typedef Status (*callback)(BiTree) ; // ���庯��ָ��

// ��������������ݽṹ
struct Element{
	BiTree ptr;
	int flag;
	Element(){ std::memset(this, 0, sizeof(Element));}
	Element( BiTree p, int flg ) : ptr(p), flag(flg) {}
};

// ������������������
BiTree create_bitree( const ElemType* arr, int cur );

Status pre_order( BiTree root,  callback visit);
Status pre_order_without_recursion( BiTree root, callback visit );
Status in_order( BiTree root, callback visit );
Status in_order_without_recursion( BiTree root, callback visit );
Status post_order( BiTree root, callback visit );
Status post_order_without_recursion( BiTree root, callback visit );
Status level_order( BiTree root, callback visit );

#endif