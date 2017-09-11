#include <iostream>
#include "UnionFindSet.h"

Status make_set( int* tree, int n ){
	if( !tree || n < 1 ){
		std::cerr << "Invalid arguments!" << std::endl;
		return ERROR;
	}
	for( int i = 1; i <= n; ++i ){
		tree[i] = -1;
	}
	return OK;
}
int find_set( int* tree, int i ){
	if( !tree || i < 1 )
		return 0;

	if( -1 == tree[i] )
		return i;
	else{
		int ret = find_set( tree, tree[i] );
		tree[i] = ret;
		return ret;
	}
}
bool union_set( int* tree, int i, int j ){
	if( !tree || i < 1 || j < 1 ){
		std::cerr << "Invalid arguments" << std::endl;
		return ERROR;
	}
	int a = find_set( tree, i );
	int b = find_set( tree, j );
	if( a != b ){ 
		tree[b] = a;
		return true;
	}
	else
		return false;
}