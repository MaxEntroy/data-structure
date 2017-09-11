/*************************************************************************
	> File Name: main.cpp
	> Author: Kang
	> Mail:likang@tju.edu.cn 
	> Created Time: 2017年08月06日 星期日 11时36分17秒
 ************************************************************************/
#include <iostream>
#include <algorithm>
#include "Search.h"


int main( void ){
	
	int arr[] = { 62, 34, 115, 18, 9, 89 };
	int n = sizeof(arr)/sizeof(int);

	int key1 = 9;
	int key2 = 10;

	// test of seq_search
	int ret = seq_search( arr, n, key1 );
	std::cout << ret << std::endl;
	ret = seq_search( arr, n, key2 );
	std::cout << ret << std::endl;

	// test of bi_search
	std::sort( arr, arr+n ); // sort the arr first

	ret = bi_search_without_recursion( arr, n, key1 );
	std::cout << ret << std::endl;
	ret = bi_search_without_recursion( arr, n, key2 );
	std::cout << ret << std::endl;

	ret = bi_search( arr, n, key1 );
	std::cout << ret << std::endl;
	ret = bi_search( arr, n, key2 );
	std::cout << ret << std::endl;

	return 0;
}
