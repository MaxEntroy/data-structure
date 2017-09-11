#ifndef SeqList_H
#define SeqList_H
#include "common.h"

Status print( const ElemType* arr, int n );				// ˳����ӡ
Status find_x( const ElemType* arr, int n, ElemType x );// ˳������
Status insert_x( ElemType* arr, int& n, ElemType x );	// ����˳������
Status delete_x( ElemType* arr, int& n, ElemType x );   // ˳���ɾ��
Status delete_allx( ElemType* arr, int& n, ElemType x );// ɾ��˳�������λx��Ԫ�� 
Status delete_allxy( ElemType* arr, int& n, ElemType x, ElemType y ); // // ɾ��˳�������λ��x��y֮���Ԫ�� O(n)ʵ��
Status delete_same( ElemType* arr, int& n );			// ɾ��˳����е��ظ�Ԫ��
	
Status reverse( ElemType* arr, int n );				// ����
Status is_palindrome( const ElemType* arr, int n ); // �жϻ���

Status move_left( ElemType* arr, int n, int k );	// ѭ������kλ
Status move_left1( ElemType* arr, int n, int k );	// ѭ������kλ

Status move_right( ElemType* arr, int n, int k );	// ѭ������kλ
Status move_right1( ElemType* arr, int n, int k );	// ѭ������kλ
Status move_right2( ElemType* arr, int n, int k );	// ѭ������kλ

Status adjust( ElemType* arr, int n, Status (*compare)(ElemType) ); // ������compare()��Ԫ�ص����������ǰ�棬������ĵ���������ĺ���

ElemType* merge( ElemType* arr1, int n1, ElemType* arr2, int n2 );  // �鲢���������
ElemType* merge1( ElemType* arr1, int n1, ElemType* arr2, int n2 ); // �鲢��������������ظ�Ԫ��

#endif

