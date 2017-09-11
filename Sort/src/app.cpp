#include <iostream>
#include "app.h"
ElemType top_k( ElemType* arr, int n, int k ){
	if(!arr || k > n || k < 1){
		std::cerr << "Invalid arguments!";
		return (ElemType)ERROR;
	}
	int pivot = -1;
	int low = 0, high = n-1;
	while( 1 ){
		pivot = partition( arr, low, high );
		if(pivot == k-1) break;
		else if( pivot < k-1 ) low = pivot + 1;
		else high = pivot-1;
	}
	return arr[pivot];
}

