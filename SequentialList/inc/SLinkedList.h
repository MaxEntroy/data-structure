#ifndef SLinkedList_H
#define SLinkedList_H
#include "common.h"

#define MAXSIZE 1024 //�������󳤶�

/* ��̬����ڵ����� */
struct SListNode{
	ElemType data;
	int next;

	SListNode() : data(0), next(-1) {}
	SListNode( ElemType x ) : data(x), next(-1) {}
};

typedef SListNode* SLinkedList;  

/* ��̬�����ڴ������� */
Status init_sl( SLinkedList slist ); // ������ռ��ʼ��Ϊ����
int malloc_sl( SLinkedList slist ); // ���ٽڵ�ռ�
Status free_sl( SLinkedList slist, int k ); // ���սڵ�ռ�


/* ��̬�����ò��� */
Status create_slinkedlist( SLinkedList slist, const ElemType* arr, int n );
Status print_slinkedlist( const SLinkedList slist );
Status insert_slinkedlist( SLinkedList slist, int i, int target );
Status delete_slinkedlist( SLinkedList slist, int i);


#endif