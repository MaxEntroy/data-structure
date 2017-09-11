/*************************************************************************
	> File Name: Search.h
	> Author: Kang
	> Mail:likang@tju.edu.cn 
	> Created Time: 2017年08月06日 星期日 11时16分47秒
 ************************************************************************/
#ifndef Search_H
#define Search_H
#include "common.h"

int seq_search( ElemType* arr, int n, ElemType key);
int bi_search( ElemType* arr, int n, ElemType key );
int bi_search_helper( ElemType* arr, int low, int high, int key ); 
int bi_search_without_recursion( ElemType* arr, int n, ElemType key );

#endif
