#include <iostream>
#include <cstring>
#include <vector>
#include "common.h"
#include "UnionFindSet.h"
#include "MyGraph.h"
//#include "MGraph.h"
//#include "ALGraph.h"
#define N 1000
int tree[N + 8];

/*
void test_for_union_find_set(){
	// 以畅通工程为例
	int n = 0, m = 0;
	while( std::cin >> n >> m, n != 0 ){
		make_set( tree, n );
		for( int i = 0; i < m; ++i ){
			int a,b;
			std::cin >> a >> b;
			union_set(tree, a, b);
		}
		int ans = 0;
		for( int i = 1; i <= n; ++i ){
			if( -1 == tree[i] ) ++ans;
		}
		std::cout << ans - 1 << std::endl;
	}
}
*/
/*
Status visit(MGraph& G, int u){
	std::cout << G.vertex[u] << std::endl;
	return OK;
}

void test_for_mgraph(){
	ElemType arr[7] = { 0, 1, 2, 3, 4, 5, 6 };
	MGraph G;
	create_graph( G, arr, 6, 9 );
	show_graph(G);
	

	int visited[ MAXSIZE ];
	std::memset(visited, 0, sizeof(visited));
	dfs_graph(G, 1, visited, visit);
	std::cout << "-----------------------" <<std::endl;
	std::memset(visited, 0, sizeof(visited));
	bfs_graph(G, 1, visited, visit);
}*/

/*
Status visit(ALGraph& graph, int u){
	std::cout << graph.adjlist[u].vertex << " ";
	return OK;
}
void test_for_algraph(){

	ElemType arr[7] = { 0, 1, 2, 3, 4, 5, 6 };
	ALGraph G;

	create_graph( G, arr, 6, 9 );
	show_graph(G);
	
	int visited[ MAXSIZE ];
	std::memset(visited, 0, sizeof(visited));
	bfs_graph( G, 1, visited, visit );
	std::cout << std::endl;

	destroy_graph(G);
	return;
}
*/
int main( void ){
	const int maxn = 3+1;
	MyGraph graph(maxn);

	create_graph( graph );
	show_graph( graph );


	return 0;
}