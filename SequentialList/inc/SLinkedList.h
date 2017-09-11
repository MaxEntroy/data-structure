#ifndef SLinkedList_H
#define SLinkedList_H
#include "common.h"

#define MAXSIZE 1024 //链表的最大长度

/* 静态链表节点声明 */
struct SListNode{
	ElemType data;
	int next;

	SListNode() : data(0), next(-1) {}
	SListNode( ElemType x ) : data(x), next(-1) {}
};

typedef SListNode* SLinkedList;  

/* 静态链表内存管理操作 */
Status init_sl( SLinkedList slist ); // 将数组空间初始化为链表
int malloc_sl( SLinkedList slist ); // 开辟节点空间
Status free_sl( SLinkedList slist, int k ); // 回收节点空间


/* 静态链表常用操作 */
Status create_slinkedlist( SLinkedList slist, const ElemType* arr, int n );
Status print_slinkedlist( const SLinkedList slist );
Status insert_slinkedlist( SLinkedList slist, int i, int target );
Status delete_slinkedlist( SLinkedList slist, int i);


#endif