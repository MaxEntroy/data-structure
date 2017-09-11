#ifndef LinkedList_H
#define LinkedList_H
#include "common.h"
#include <cstdlib>

/* ����ڵ����� */
struct ListNode
{
	ElemType data;
	ListNode* next;

	ListNode() : data(0), next(NULL) {}
	ListNode( ElemType x ) : data(x), next(NULL) {}
};

typedef ListNode* LinkedList; // LinkedList��ָ��ListNode���͵�ָ��


/* ��ͷ���Ĳ��� */
LinkedList create_by_head( const ElemType* arr, int n );    // ͷ�巨 
LinkedList create_by_tail( const ElemType* arr, int n );	// β�巨
Status destroy( LinkedList head );							// ����
Status destroy1( LinkedList head );							// ���� - �ݹ�ʵ��

Status print( LinkedList head );						// ö��
Status print1( LinkedList head );						// ö�� - �ݹ�ʵ�� - ���ú���ʱ����Ϊhead->next�����⴦��ͷ���

Status insert_x( LinkedList head, ElemType x, int i );	// �ڵ�i��λ�ý��в���
ElemType get( LinkedList head, int i );					// ����λ�ڵ�iλ��Ԫ��
Status delete_x( LinkedList head, ElemType x );			// ɾ��ֵΪx��Ԫ��
Status delete_x_i( LinkedList head, int i );			// ɾ��λ�ڵ�i��λ�õ�Ԫ��

int get_length( LinkedList head );						// ��������
bool increase( LinkedList head );						// �жϵ������Ƿ�ǵݼ�
Status move_min( LinkedList head );						// �ƶ���Сֵ�ڵ㣬 �ռ临�Ӷ�O(1)
Status min_out( LinkedList head );						// ���ǵݼ�˳�������������Ԫ�أ����ͷŽڵ���ռ�Ĵ洢�ռ䣬�ռ临�Ӷ�O(1)
Status exchange( LinkedList head, LinkedList p );		// �����ڵ�p��p�ĺ��


#endif