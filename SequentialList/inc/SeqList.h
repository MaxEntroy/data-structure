#ifndef SeqList_H
#define SeqList_H
#include "common.h"

Status print( const ElemType* arr, int n );				// 顺序表打印
Status find_x( const ElemType* arr, int n, ElemType x );// 顺序表查找
Status insert_x( ElemType* arr, int& n, ElemType x );	// 有序顺序表插入
Status delete_x( ElemType* arr, int& n, ElemType x );   // 顺序表删除
Status delete_allx( ElemType* arr, int& n, ElemType x );// 删除顺序表所有位x的元素 
Status delete_allxy( ElemType* arr, int& n, ElemType x, ElemType y ); // // 删除顺序表所有位于x与y之间的元素 O(n)实现
Status delete_same( ElemType* arr, int& n );			// 删除顺序表中的重复元素
	
Status reverse( ElemType* arr, int n );				// 置逆
Status is_palindrome( const ElemType* arr, int n ); // 判断回文

Status move_left( ElemType* arr, int n, int k );	// 循环左移k位
Status move_left1( ElemType* arr, int n, int k );	// 循环左移k位

Status move_right( ElemType* arr, int n, int k );	// 循环右移k位
Status move_right1( ElemType* arr, int n, int k );	// 循环右移k位
Status move_right2( ElemType* arr, int n, int k );	// 循环右移k位

Status adjust( ElemType* arr, int n, Status (*compare)(ElemType) ); // 将满足compare()的元素调整到数组的前面，不满足的调整到数组的后面

ElemType* merge( ElemType* arr1, int n1, ElemType* arr2, int n2 );  // 归并两个有序表
ElemType* merge1( ElemType* arr1, int n1, ElemType* arr2, int n2 ); // 归并两个有序表，不含重复元素

#endif

