#include <iostream>
#include <vector>
#include <unordered_map>
#include "common.h"
#include "Sort.h"

// 排序操作定义
Status insert_sort( ElemType* arr, int n ){
	if(!arr || n <= 0){
		std::cout << "Invalid arguments!";
		return ERROR;
	}
	if(1==n) 
		return OK;
	
	for( int i = 1; i < n; ++i ){
		ElemType cur = arr[i];
		int j = 0;
		for( j = i - 1; j >= 0 && cur < arr[j] ; --j){
			arr[j+1] = arr[j];
		}
		arr[j+1] = cur;
	}
	return OK;
}
Status insert_sort1( ElemType* arr, int n){
	if(!arr || n <= 0){
		std::cout << "Invalid arguments!";
		return ERROR;
	}
	if(1==n) 
		return OK;

	for( int i = 1; i < n; ++i ){
		ElemType cur = arr[i];
		
		int pos = -1;
		bool found = false;
		int low = 0, high = i - 1;
		while( low <= high ){
			int mid = low + (high - low)/2;
			if( cur == arr[mid] ) { pos = mid; found = true; break; }
			else if( cur < arr[mid] ) high = mid - 1;
			else low = mid + 1;
		}
		if(!found) pos = low;

		for( int k = i - 1; k >= pos; --k ){
			arr[k] = arr[k+1];
		}

		arr[pos] = cur;
	}

	return OK;
}
Status shell_sort( ElemType* arr, int n ){
	if(!arr || n <= 0){
		std::cout << "Invalid arguments!";
		return ERROR;
	}
	if(1==n) 
		return OK;

	for( int d = n/2; d > 0; d/=2 ){
		for( int i = d; i < n; ++i ){
			ElemType cur = arr[i];
			int j = 0;
			for( j = i - d; j >= 0 && cur < arr[j]; j -= d ){
				arr[j+d] = arr[j];
			}
			arr[j+d] = cur;
		}
	}
	return OK;
}
Status bubble_sort( ElemType* arr, int n ){
	if(!arr || n <= 0){
		std::cerr << "Invalid arguments!";
		return ERROR;
	}

	int exchange = n-1;
	while(exchange){
		int bound = exchange; // bound是无序区边界
		exchange = 0;

		for(int j = 0; j < bound; ++j){
			if( arr[j] > arr[j+1] )
			{	
				swap( arr[j], arr[j+1] );
				exchange = j;
			}
		}
	}

	return OK;
}
Status bubble_sort1( ElemType* arr, int n ){
	if(!arr || n <= 0){
		std::cerr << "Invalid arguments!";
		return ERROR;
	}
	for(int i = 0; i < n-1; ++i){
		for(int j = 0; j < n-i-1; ++j){
			if( arr[j] > arr[j+1] )
				swap( arr[j], arr[j+1] );
		}
	}
	return OK;
}
Status bubble_sort2( ElemType* arr, int n ){
	if(!arr || n <= 0){
		std::cerr << "Invalid arguments!";
		return ERROR;
	}
	for(int i = 0; i < n-1; ++i){
		for(int j = n-1; j > i; --j){
			if( arr[j] < arr[j-1] )
				swap( arr[j], arr[j-1] );
		}
	}
	return OK;
}
Status quick_sort( ElemType* arr, int n ){
	if(!arr || n <= 0){
		std::cerr << "Invalid arguments!";
		return ERROR;
	}

	quick_sort_helper(arr, 0, n-1);
	return OK;
}
Status maxheap_sort( ElemType* arr, int n ){
	if(!arr || n <= 0){
		std::cerr << "Invalid arguments!";
		return ERROR;
	}

	for(int i = n/2 - 1; i >= 0; --i){
		maxsift( arr, i, n-1 );
	}
	for(int i = 0; i < n-1; ++i){
		swap( arr[0], arr[n-1-i] );
		maxsift( arr, 0, n-2-i );
	}

	return OK;
}
Status minheap_sort( ElemType* arr, int n ){
	if(!arr || n <= 0){
		std::cerr << "Invalid arguments!";
		return ERROR;
	}

	for(int i = n/2 - 1; i >= 0; --i){
		minsift( arr, i, n-1 );
	}
	for(int i = 0; i < n-1; ++i){
		swap( arr[0], arr[n-1-i] );
		minsift( arr, 0, n-2-i );
	}

	return OK;
}
Status merge_sort( ElemType* arr, int n ){
	if(!arr || n <= 0){
		std::cerr << "Invalid arguments!";
		return ERROR;
	}
	merge_sort_helper( arr, 0, n-1 );
	return OK;
}
Status count_sort( ElemType* arr, int n ){
	if(!arr || n <= 0){
		std::cerr << "Invalid arguments!";
		return ERROR;
	}

	ElemType min = arr[0];
	ElemType max = arr[0];
	for( int i = 1; i < n; ++i ){
		if( arr[i] < min ) min = arr[i];
		if( arr[i] > max ) max = arr[i];
	}

	std::unordered_map< ElemType, int > counter;
	for( int i = 0; i < n; ++i ){
		if( counter.find( arr[i] ) == counter.end() ) counter[ arr[i] ] = 1;
		else counter[ arr[i] ] += 1;
	}

	int cnt = 0;
	for( ElemType x = min; x <= max; ++x ){
		if( counter.find( x ) != counter.end() ){
			int num = counter[x];
			while(num--) arr[cnt++] = x;
		}
	}
	return OK;
}

// 辅助操作定义
Status swap(ElemType& a, ElemType& b){
	int t = a;
	a = b;
	b = t;

	return OK;
}
int partition(ElemType* arr, int low, int high){
	if(!arr || low > high){
		std::cerr << "Invalid arguments!";
		return -1;
	}

	int i = low, j = high;
	while(i < j){
		while( i < j && arr[i] < arr[j] ) --j;
		if(i<j){ // 右侧扫描，将小元素交换到前面
			swap( arr[i], arr[j] );
			++i;
		}
		while( i < j && arr[i] < arr[j] ) ++i;
		if(i < j){ // 左侧扫描，将大元素交换到后面
			swap( arr[i], arr[j] );
			--j;
		}
	}
	return i;
}
Status quick_sort_helper( ElemType* arr, int low, int high ){
	if(!arr){
		std::cerr << "Invalid arguments!";
		return ERROR;
	}
	if( low < high ){
		int pivot = partition( arr, low, high );
		quick_sort_helper( arr, low, pivot-1 );
		quick_sort_helper( arr, pivot+1, high );
	}

	return OK;
}
Status maxsift( int* arr, int i, int m ){
	if(!arr || m < 0){
		std::cerr << "Invalid arguments!";
		return ERROR;
	}

	int j = 2*i + 1; // left child
	while(j <= m){
		if( j < m && arr[j] < arr[j+1] ) ++j;
		if( arr[i] > arr[j] ) break;
		else{
			swap( arr[i], arr[j] );
			i = j; j = 2*i + 1;
		}
	}
	return OK;
}
Status minsift( int* arr, int i, int m ){
	if(!arr || m < 0){
		std::cerr << "Invalid arguments!";
		return ERROR;
	}
	int j = 2*i+1;
	while( j <= m ){
		if( j+1 <=m && arr[j+1] < arr[j] ) ++j;
		if(arr[i] < arr[j]) break;
		else{
			swap( arr[i], arr[j] );
			i = j; j = 2*i+1;
		}
	}
	return OK;
}
Status merge_sort_helper( ElemType* arr, int low, int high ){
	if(!arr){
		std::cerr << "Invalid arguments!";
		return ERROR;
	}
	if(low < high){ // 区间存在
		int mid = (low+high)/2;
		merge_sort_helper( arr, low, mid );
		merge_sort_helper( arr, mid+1, high );
		merge( arr, low, mid, high );
	}
	return OK;
}
Status merge( ElemType* arr, int low, int mid, int high ){
	if(!arr || low > high ){
		std::cerr << "Invalid arguments!";
		return ERROR;
	}
	std::vector<ElemType> tmp(high-low+1);
	int s1 = low, t1 = mid;
	int s2 = mid+1, t2 = high;
	int i = s1, j = s2;
	int k = 0;
	while( i <= t1 && j <= t2 ){
		tmp[k++] = (arr[i] < arr[j])?arr[i++]:arr[j++];
	}
	while( i <= t1 ){
		tmp[k++] = arr[i++];
	}
	while( j <= t2 ){
		tmp[k++] = arr[j++];
	}
	for( int idx = 0; idx < k; ++idx ){
		arr[low++] = tmp[idx];
	}
	return OK;
}