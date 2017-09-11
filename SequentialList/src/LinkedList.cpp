#include "LinkedList.h"
#include <iostream>
#include <stack>

/* 带头结点的操作 */

LinkedList create_by_head( const ElemType* arr, int n )
{
	if( NULL == arr || n <= 0 )
	{
		std::cerr << "Invalid arguments!" << std::endl;
		return NULL;
	}

	LinkedList head = new ListNode();
	if( !head )
	{
		std::cerr << "Not enough space!" << std::endl;
		return NULL;
	}

	for( int i = 0; i < n; ++i )
	{
		LinkedList cur = new ListNode( arr[i] );
		if(!cur)
		{
			std::cerr << "Not enough space!" << std::endl;
			return NULL;
		}

		cur->next = head->next;
		head->next = cur;

	}

	return head;
}
LinkedList create_by_tail( const ElemType* arr, int n )
{
	if( NULL == arr || n <= 0 )
	{
		std::cerr << "Invalid arguments" << std::endl;
		return NULL;
	}

	LinkedList head = new ListNode();
	if( !head )
	{
		std::cerr << "Not enough space!" << std::endl;
		return NULL;
	}

	LinkedList tail = head;
	for( int i = 0; i < n; ++i )
	{
		LinkedList cur = new ListNode( arr[i] );
		if( !cur )
		{
			std::cerr << "Not enough space!" << std::endl;
			return NULL;
		}

		tail->next = cur;
		tail = cur;
	}

	return head;
}
Status destroy( LinkedList head )
{
	if(!head)
	{
		std::cerr << "Invalid arguments" << std::endl;
		return ERROR;
	}

	std::stack<LinkedList> stk;
	LinkedList p = head->next;
	while( p )
	{
		stk.push( p );
		p = p->next;
	}

	while( !stk.empty() )
	{
		delete stk.top();
		stk.pop();
	}

	return OK;
}
Status destroy1( LinkedList head )
{
	if( head )
	{
		destroy1( head->next );
		delete head;
	}
	return OK;
}

Status print( LinkedList head )
{
	if( !head )
	{
		std::cerr << "Invalid arguments" << std::endl;
		return ERROR;
	}
	LinkedList p = head->next;

	while( p )
	{
		std::cout << p->data << " "; 
		p = p->next;
	}
	std::cout << std::endl;

	return OK;
}
Status print1( LinkedList head )
{
	if( head )
	{
		std::cout << head->data << " ";
		print1( head->next );
	}
	return OK;
}

Status insert_x( LinkedList head, ElemType x, int i )
{
	if( NULL == head || i < 1 )
	{
		std::cerr << "Invalid arguments!" << std::endl;
		return ERROR;
	}

	LinkedList p = head->next;
	int j = 1;
	while( p && j < i - 1 )
	{
		p = p->next;
		++j;
	}
	if( p )
	{
		LinkedList cur = new ListNode( x );
		if( !cur )
		{
			std::cerr << "Not enough space!" << std::endl;
			return ERROR;
		}

		cur->next = p->next;
		p->next = cur;
		return OK;
	}
	else
	{
		std::cerr << i << " is not exits!" << std::endl;
		return ERROR;
	}
	
}
ElemType get( LinkedList head, int i )
{
	if( !head )
	{
		std::cerr << "Invalid arguments!" << std::endl;
		return ERROR;
	}

	LinkedList p = head->next;
	int j = 1;
	while( p && j < i )
	{
		p = p->next;
		++j;
	}
	if(p)
	{
		return p->data;
	}
	else
	{
		std::cerr << i << " is not exits!" << std::endl;
		return ERROR;
	}
}
Status delete_x( LinkedList head, ElemType x )
{
	if( !head )
	{
		std::cerr << "Invalid arguments!" << std::endl;
		return ERROR;
	}

	LinkedList pre = head;
	LinkedList p = head->next;
	while( p && p->data != x )
	{
		pre = p;
		p = p->next;
	}
	if( p )
	{
		pre->next = p->next;
		delete p;
		p = NULL;

		return OK;
	}
	else
	{
		std::cerr  << x << " is not exits!" << std::endl;
		return ERROR;
	}
}
Status delete_x_i( LinkedList head, int i )
{
	if( !head )
	{
		std::cerr << "Invalid argumets!" << std::endl;
		return ERROR;
	}

	LinkedList pre = head;
	LinkedList p = head->next;
	int j = 1;

	while( p && j < i  )
	{
		pre = p;
		p = p->next;
		++j;
	}
	if( p )
	{
		pre->next = p->next;
		delete p;
		p = NULL;

		return OK;
	}
	else
	{
		std::cerr << i << " is not exists! " << std::endl;
		return ERROR;
	}

}

int get_length( LinkedList head )
{
	if( !head )
	{
		std::cerr << "Invalid arguments!" << std::endl;
		return -1;
	}

	int length = 0;
	LinkedList p = head->next;
	while( p )
	{
		++length;
		p = p->next;
	}
	return length;
}
bool increase( LinkedList head )
{
	if( !head )
	{
		std::cerr << "Invalid arguments!" << std::endl;
		return false;
	}

	LinkedList pre = head->next;
	if(!pre)
		return false;
	LinkedList p = pre->next;
	while( p )
	{
		if( pre->data > p->data )
			return false;
		pre = p;
		p = p->next;
	}
	return true; // 不存在逆序
}
Status move_min( LinkedList head )
{
	if( !head )
	{
		std::cerr << "Invalid arguments!" << std::endl;
		return ERROR;
	}

	LinkedList pre = head;
	LinkedList p = head->next;

	LinkedList pre_min = pre;
	LinkedList min = p;

	while( p )
	{
		if( p->data < min->data )
		{	
			pre_min = pre;
			min = p;
		}
		
		pre = p;
		p = p->next;
	}
	if( min != head->next )
	{
		pre_min->next = min->next;
		min->next = head->next;
		head->next = min;
	}

	return OK;
}
Status min_out( LinkedList head )
{
	if( !head )
	{
		std::cerr << "Invalid arguments!" << std::endl;
		return NULL;
	}

	LinkedList p = NULL;
	LinkedList pre = NULL;
	while( pre = head, p = head->next )
	{
		LinkedList pre_min = head;
		LinkedList min = p;
		while( p )
		{
			if( p->data < min->data )
			{
				pre_min = pre;
				min = p;
			}

			pre = p;
			p = p->next;
		}
		std::cout << min->data << std::endl;
		pre_min->next = min->next;
		delete min;
	}
	return OK;
}
Status exchange( LinkedList head, LinkedList p )
{
	if( !head || !p )
	{
		std::cerr << "Invalid arguments!" << std::endl;
		return ERROR;
	}
	LinkedList pre = head;
	LinkedList cur = head->next;
	while( cur && cur != p )
	{
		pre = cur;
		cur = cur->next;
	}
	if( cur != p )
	{
		std::cerr << "p is not exists!" << std::endl;
		return ERROR;
	}
	LinkedList rear = cur->next;
	if( !rear )
	{
		std::cerr << "p->next is not exits!" << std::endl;
		return ERROR;
	}

	cur->next = rear->next;
	pre->next = rear;
	rear->next = cur;

	return OK;
}