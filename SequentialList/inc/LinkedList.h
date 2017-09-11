#ifndef LinkedList_H
#define LinkedList_H
#include "common.h"
#include <cstdlib>

/* 链表节点声明 */
struct ListNode
{
	ElemType data;
	ListNode* next;

	ListNode() : data(0), next(NULL) {}
	ListNode( ElemType x ) : data(x), next(NULL) {}
};

typedef ListNode* LinkedList; // LinkedList是指向ListNode类型的指针


/* 带头结点的操作 */
LinkedList create_by_head( const ElemType* arr, int n );    // 头插法 
LinkedList create_by_tail( const ElemType* arr, int n );	// 尾插法
Status destroy( LinkedList head );							// 销毁
Status destroy1( LinkedList head );							// 销毁 - 递归实现

Status print( LinkedList head );						// 枚举
Status print1( LinkedList head );						// 枚举 - 递归实现 - 调用函数时参数为head->next，避免处理头结点

Status insert_x( LinkedList head, ElemType x, int i );	// 在第i个位置进行插入
ElemType get( LinkedList head, int i );					// 查找位于第i位的元素
Status delete_x( LinkedList head, ElemType x );			// 删除值为x的元素
Status delete_x_i( LinkedList head, int i );			// 删除位于第i个位置的元素

int get_length( LinkedList head );						// 求单链表长度
bool increase( LinkedList head );						// 判断单链表是否非递减
Status move_min( LinkedList head );						// 移动最小值节点， 空间复杂度O(1)
Status min_out( LinkedList head );						// 按非递减顺序输出单链表中元素，并释放节点所占的存储空间，空间复杂度O(1)
Status exchange( LinkedList head, LinkedList p );		// 交换节点p和p的后继


#endif