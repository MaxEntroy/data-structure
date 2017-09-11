#include "SeqList.h"
#include <cstdlib>
#include <iostream>
#include <map>

Status print( const ElemType* arr, int n )
{
	if( NULL == arr || n <= 0 )
	{
		std::cout << "Invalid arguments !" << std::endl;
		return ERROR;
	}

	for( int i = 0; i < n; ++i )
	{
		std::cout << arr[i] << std::endl;
	}

	return OK;
}
Status find_x( const ElemType* arr, int n, ElemType x )
{
	if( NULL == arr || n <= 0 )
	{	
		std::cerr << "Invalid arguments !" << std::endl;
		return ERROR;
	}

	for( int i = 0; i < n; ++i )
	{
		if( arr[i] == x )
			return i;
	}

	return OK;
}
Status insert_x( ElemType* arr, int& n, ElemType x )
{
	if( NULL == arr || n <= 0 )
	{
		std::cerr << "Invalid arguments!" << std::endl;
		return ERROR;
	}

	int loc = 0;
	while( loc<n && arr[loc] < x ) ++loc;

	if( loc < n )
	{
		for( int i = n-1; i >= loc; --i )
			arr[i+1] = arr[i];
		arr[loc] = x;
	}
	else
		arr[loc] = x;

	++n;

	return OK;
}
Status delete_x( ElemType* arr, int& n, ElemType x )
{
	if( NULL == arr || n <= 0 )
	{
		std::cerr << "Invalid arguments!" << std::endl;
		return ERROR;
	}
	int loc = 0;
	while( loc < n && arr[loc] != x ) ++loc;

	if( loc < n )
	{
		for( int i = loc+1; i < n; ++i )
			arr[i-1] = arr[i];

		--n;
		return OK;
	}
	else
	{
		std::cerr << x << " not in the SeqList" << std::endl;
		return ERROR;
	}
}
Status delete_allx( ElemType* arr, int& n, ElemType x )
{
	if( NULL == arr || n <= 0 )
	{
		std::cerr << "Invalid arguments!" << std::endl;
		return ERROR;
	}
	int cnt_x = 0; // 元素值为x的数量
	for( int i = 0; i < n; ++i )
	{
		if( arr[i] == x )
		{	
			++cnt_x;
			continue;
		}
		
		arr[i - cnt_x] = arr[i];
	}
	n -= cnt_x;

	return OK;
}
Status delete_allxy( ElemType* arr, int& n, ElemType x, ElemType y )
{
	if( NULL == arr || n <= 0 || x > y )
	{
		std::cerr << "Invalid arguments!" << std::endl;
		return ERROR;
	}

	int cnt_xy = 0;
	for( int i = 0; i < n; ++i )
	{
		if( x <= arr[i] && arr[i] <= y )
		{
			++cnt_xy;
			continue;
		}

		arr[i - cnt_xy] = arr[i];
	}
	n -= cnt_xy;
	 
	return OK;
}
Status delete_same( ElemType* arr, int& n )
{
	if( NULL == arr || n <= 0 )
	{
		std::cerr << "Invalid arguments!" << std::endl;
		return ERROR;
	}

	std::map< ElemType, bool > hash ;

	int cnt_same = 0;

	for( int i = 0; i < n; ++i )
	{
		if( hash.find( arr[i] ) == hash.end() )
		{
			hash[arr[i]] = true;
			arr[i - cnt_same] = arr[i];
		}
		else
		{
			++cnt_same;
			continue;
		}
	}

	n -= cnt_same;


	return OK;
}


Status reverse( ElemType* arr, int n )
{
	if( NULL == arr || n <= 0 )
	{	
		std::cerr << "Invalid arguments!" << std::endl;
		return ERROR;
	}

	int mid = n/2; // 中轴
	for( int i = 0; i < mid; ++i )
	{
		ElemType t = arr[i];
		arr[i] = arr[n - 1 - i];
		arr[n - 1 - i] = t;
	}

	return OK;
}
Status is_palindrome( const ElemType* arr, int n )
{
	if( NULL == arr || n <= 0 )
	{	
		std::cerr << "Invalid arguments!" << std::endl;
		return FALSE;
	}

	int mid = n/2; // 中轴
	for( int i = 0; i < mid; ++i )
	{
		if( arr[i] != arr[n-1-i] )
			return FALSE;
	}
	return TRUE;
}

Status move_left( ElemType* arr, int n, int k )
{
	if( NULL == arr || n <= 0 || k < 0 || k >= n )
	{
		std::cerr << "Invalid arguments!" << std::endl;
		return ERROR;
	}

	ElemType* tmp = new ElemType[k];
	if( NULL == tmp )
	{
		std::cerr << "Not enough space!" << std::endl;
		return ERROR;
	}

	for( int i = 0; i < k; ++i )
	{
		tmp[i] = arr[i];
	}
	for( int i = k; i < n; ++i ) 
	{
		arr[i-k] = arr[i];
	}
	for( int i = n - 1, j = k - 1; i >= n-k; --i, --j )
	{
		arr[i] = tmp[j];
	}

	delete tmp;
	return OK;
}
/*
改进算法：
这个问题可以看做把数组ab转换为数组ba(a代表前k个元素，b代表后n-k个元素)
arr[k n-k] 转化为 arr[ n-k k ]
	1.a置逆得到 a^-1 b
	2.b置逆得到 a^-1 b^-1
	3.最后将整个数组置逆得到 ba
本质是该公式(a^-1b^-1)^-1 = ba。一维数组置逆就是从左至右交换一次。
*/
Status move_left1( ElemType* arr, int n, int k )
{
	if( NULL == arr || n <= 0 || k < 0 || k >= n )
	{
		std::cerr << "Invalid arguments!" << std::endl;
		return ERROR;
	}

	reverse( arr, k );
	reverse( arr + k, n-k );
	reverse( arr, n );

	return OK;
}
Status move_right( ElemType* arr, int n, int k )
{
	if( NULL == arr || n <= 0 || k >= n )
	{
		std::cerr << "Invalid arguments!" << std::endl;
		return -1;
	}

	ElemType* tmp = new ElemType[k];
	if( NULL == tmp )
	{
		std::cerr << "Not enough space!" << std::endl;
		return ERROR;
	}
	for( int i = n-k, j = 0; i < n; ++i, ++j )
	{
		tmp[j] = arr[i];
	}
	for( int i = n-k-1; i >= 0; --i )
	{
		arr[i+k] = arr[i];
	}
	for( int i = 0, j = 0; i < k; ++i, ++j )
	{
		arr[i] = tmp[j];
	}

	delete tmp;
	return OK;
}
Status move_right1( ElemType* arr, int n, int k )
{
	if( NULL == arr || n <= 0 || k >= n )
	{
		std::cerr << "Invalid arguments!" << std::endl;
		return -1;
	}

	reverse( arr, n-k );
	reverse( arr + n-k, k );
	reverse( arr, n );

	return OK;
}
Status move_right2( ElemType* arr, int n, int k )
{
	if( NULL == arr || n <= 0 || k >= n )
	{
		std::cerr << "Invalid arguments!" << std::endl;
		return ERROR;
	}

	Status ret = move_right( arr, n, n-k );

	return ret;
}

Status adjust( ElemType* arr, int n, Status (*compare)(ElemType) )
{
	if( NULL == arr || n <=0 || NULL == compare )
	{
		std::cerr << "Invalid arguments!" << std::endl;
		return ERROR;
	}
	
	int i = 0;
	int j = n - 1;
	while( i < j ) // 调整没有结束
	{
		while( i < j && compare(arr[i]) ) ++i;
		while( i < j && !compare(arr[j]) ) --j;
		if( i < j )
		{
			ElemType t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;

			++i; --j;
		}
	}

	return OK;
}
ElemType* merge( ElemType* arr1, int n1, ElemType* arr2, int n2 )
{
	if( NULL == arr1 || n1 <= 0 || NULL == arr2 || n2 <= 0 )
	{
		std::cerr << "Invalid arguments!" << std::endl;
		return NULL;
	}

	ElemType* arr3 = new ElemType[ n1 + n2 ];
	if( NULL == arr3 )
	{
		std::cerr << "Not enough space!" << std::endl;
		return NULL;
	}

	int i = 0;
	int j = 0;
	int k = 0;
	while( i < n1 && j < n2 )
	{
		if( arr1[i] < arr2[j] )
		{
			arr3[k++] = arr1[i++];
		}
		else
		{
			arr3[k++] = arr2[j++];
		}
	}
	while( i < n1 ) 
		arr3[k++] = arr1[i++];
	while( j < n2 )
		arr3[k++] = arr2[j++];

	return arr3;
}
ElemType* merge1( ElemType* arr1, int n1, ElemType* arr2, int n2 )
{

	if( NULL == arr1 || n1 <= 0 || NULL == arr2 || n2 <= 0 )
	{
		std::cerr << "Invalid arguments!" << std::endl;
		return NULL;
	}

	ElemType* arr3 = new ElemType[ n1 + n2 ];
	if( NULL == arr3 )
	{
		std::cerr << "Not enough space!" << std::endl;
		return NULL;
	}

	int i = 0;
	int j = 0;
	int k = 0;
	while( i < n1 && j < n2 )
	{
		if( arr1[i] < arr2[j] )
		{
			arr3[k++] = arr1[i++];
		}
		else if( arr1[i] > arr2[j] )
		{
			arr3[k++] = arr2[j++];
		}
		else
		{
			arr3[k++] = arr1[i++];
			j++;
		}
	}
	while( i < n1 ) 
		arr3[k++] = arr1[i++];
	while( j < n2 )
		arr3[k++] = arr2[j++];

	return arr3;
}