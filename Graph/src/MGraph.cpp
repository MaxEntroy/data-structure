#include <iostream>
#include <fstream>
#include <queue>
#include "MGraph.h"
#define LOCAL // for test

// 创建邻接矩阵
Status create_graph( MGraph& graph, const ElemType* arr, int n, int e ){
	if( !arr || n <= 0 ){
		std::cerr << "Invalid arguments!" << std::endl;
		return ERROR;
	}
	graph.vertex_num = n;
	graph.edge_num = e;
	
	for( int i = 1; i <= graph.vertex_num; ++i){ // 顶点值从1开始，下标也从1开始
		graph.vertex[i] = arr[i];
	}
#ifdef LOCAL
	std::ifstream cin( "input.dat" );
#endif
	for( int i = 0; i < graph.edge_num; ++i ){
		int u,v;
		//std::cin >> u >> v;
		cin >> u >> v;
		graph.arc[u][v] = 1;
#ifdef UNDIRECTED
		graph.arc[v][u] = 1;
#endif
	}
#ifdef LOCAL
	cin.close();
#endif
	return OK;
}

// 输出邻接矩阵
Status show_graph(MGraph& graph){

	for( int u = 1; u <= graph.vertex_num; ++u ){
		for( int v = 1; v <= graph.vertex_num; ++v ){
			std::cout << graph.arc[u][v] << " ";
		}
		std::cout << std::endl;
	}

	return OK;
}

// 深度优先遍历
Status dfs_graph(MGraph& graph, int u, int* visited, callback visit){
	if(u < 1 || !visited || !visit){
		std::cerr << "Invalid arguments!";
		return ERROR;
	}

	visited[u] = 1;
	visit(graph, u);

	for( int v = 1; v <= graph.vertex_num; ++v ){
		if( graph.arc[u][v] && !visited[v] )
			dfs_graph( graph, v, visited, visit );
	}
	return OK;
}

// 广度优先遍历
Status bfs_graph(MGraph& graph, int u, int* visited, callback visit){
	if(u < 1 || !visited || !visit){
		std::cerr << "Invalid arguments!";
		return ERROR;
	}

	std::queue<int> que;
	
	visited[u] = 1;
	visit(graph, u);
	que.push(u);
	while(!que.empty()){
		u = que.front();
		que.pop();

		for( int v = 1; v <= graph.vertex_num; ++v ){
			if( graph.arc[u][v] && !visited[v] ){
				visited[v] = 1;
				visit(graph, v);
				que.push(v);
			}
		}
	}
	return OK;
}