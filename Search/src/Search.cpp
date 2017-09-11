/*************************************************************************
	> File Name: Search.cpp
	> Author: Kang
	> Mail:likang@tju.edu.cn 
	> Created Time: 2017年08月06日 星期日 11时25分39秒
 ************************************************************************/
#include <iostream>
#include "Search.h"

int seq_search( ElemType* arr, int n, ElemType key ){
	if( !arr || n < 1 ){
		std::cerr << "Invalid arguments!" ;
		return -1;
	}

	for( int i = 0; i < n; ++i ){
		if( arr[i] == key )
			return i;
	}

	return -1;
}

int bi_search( ElemType* arr, int n, ElemType key ){
	if( !arr || n < 1 ){
		std::cerr << "Invalid arguments!" ;
		return -1;
	}

	return bi_search_helper( arr, 0, n-1, key );
}

int bi_search_helper( ElemType* arr, int low, int high, ElemType key ){
	if( !arr ){
		std::cerr << "Invalid arguments!" ;
		return -1;
	}
	
	if( low > high ) return -1;
	
	int mid = low + (high - low)/2;
	if( key == arr[mid] ) return mid;
	else if( key < arr[mid] ) return bi_search_helper( arr, low, mid-1, key );
	else return bi_search_helper( arr, mid+1, high, key );
}

int bi_search_without_recursion( ElemType* arr, int n, int key ){
	if(!arr || n < 1){
		std::cerr << "Invalid arguments!" << std::endl;
		return -1;
	}

	int low = 0;
	int high = n-1;

	while(low <= high){
		int mid = low + (high-low)/2;
		if( key == arr[mid] ) return mid;
		else if( key < arr[mid] ) high = mid-1;
		else low = mid + 1;
	}
	return -1;
}
