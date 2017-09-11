#ifndef SORT_H
#define SORT_H
#include "common.h"

// �����������
Status insert_sort( ElemType* arr, int n ); // ��������
Status insert_sort1( ElemType* arr, int n); // �۰���Ҳ�������
Status shell_sort( ElemType* arr, int n );  // ϣ������
Status bubble_sort( ElemType* arr, int n ); // ð������
Status bubble_sort1( ElemType* arr, int n );// ð������ - ���׷�
Status bubble_sort2( ElemType* arr, int n );// ð������ - ð�ݷ�
Status select_sort( ElemType* arr, int n ); // ѡ������
Status quick_sort( ElemType* arr, int n );  // ��������
Status maxheap_sort( ElemType* arr, int n );// ������ - ����� - ����
Status minheap_sort( ElemType* arr, int n );// ������ - С���� - ����
Status merge_sort( ElemType* arr, int n );  // ��·�鲢����
Status count_sort( ElemType* arr, int n ); // ��������

// ������������
Status swap(ElemType& a, ElemType& b);
int partition(ElemType* arr, int low, int high);
Status quick_sort_helper( ElemType* arr, int low, int high );
Status maxsift( int* arr, int i, int m );
Status minsift( int* arr, int i, int m );
Status merge_sort_helper( ElemType* arr, int low, int high );
Status merge( ElemType* arr, int low, int mid, int high );


#endif