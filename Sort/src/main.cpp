//#include "Sort.h"
#include "common.h"
#include "app.h"
#include <iostream>
typedef Status (*callback)(ElemType* arr, int n);

void test( ElemType* arr, int n, callback mysort ){
	mysort( arr, n );
	for(int i = 0; i < n; ++i){
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main(){

	const int maxn = 10;
	int arr[maxn];
	for(int i = 0; i < maxn; ++i){
		arr[i] = maxn - i;
	}

	//test( arr, maxn, merge_sort );

	int ans = top_k( arr, maxn, 1 );
	std::cout << ans << std::endl;

	return 0;
}