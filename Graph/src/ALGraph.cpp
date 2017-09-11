#include <iostream>
#include <fstream>
#include <queue>
#include "ALGraph.h"
#include "common.h"
#define LOCAL

// 创建邻接表
Status create_graph( ALGraph& graph, const ElemType* arr, int n, int e ){
	if(!arr || n <= 0){
		std::cerr << "Invalid arguments!" << std::endl;
		return ERROR;
	}

	graph.vertex_num = n;
	graph.edge_num = e;
	for(int i = 1; i <= n; ++i){
		graph.adjlist[i].vertex = arr[i];
	}
#ifdef LOCAL
	std::ifstream cin( "input.dat" );
#endif
	// 针对无向图
	for( int i = 0; i < e; ++i ){
		int u = 0, v = 0;
		//std::cin >> u >> v;
		cin >> u >> v;

		EdgeNode* pedge = new EdgeNode( v );
		pedge->next = graph.adjlist[u].first_edge;
		graph.adjlist[u].first_edge = pedge;

		EdgeNode* pedge1 = new EdgeNode( u );
		pedge1->next = graph.adjlist[v].first_edge;
		graph.adjlist[v].first_edge = pedge1;
	}
#ifdef LOCAL
	cin.close();
#endif
	return OK;
}

// 销毁邻接表
Status destroy_graph( ALGraph& graph ){
	for( int i = 1; i <= graph.vertex_num; ++i ){
		EdgeNode* p = graph.adjlist[i].first_edge;
		while( p ){
			EdgeNode* q = p->next;
			delete p;
			p = q;
		}
	}
	return OK;
}

// 输出邻接表
Status show_graph(ALGraph& graph){
	for( int i = 1; i <= graph.vertex_num; ++i ){
		std::cout << i << "->";
		EdgeNode* p = graph.adjlist[i].first_edge;
		int first = 1;
		while(p){
			if(first){
				std::cout << p->adj_vertex ;
				first = 0;
			}
			else
				std::cout << "->" << p->adj_vertex; 
			
			p = p->next;
		}
		std::cout << std::endl;
	}
	return OK;
}

// 深度优先遍历
Status dfs_graph(ALGraph& graph, int u, int* visited, callback visit ){
	if( u < 1 || !visited || !visit ){
		std::cerr << "Invalid arguments!";
		return ERROR;
	}

	visit( graph, u );
	visited[u] = 1;

	EdgeNode* p = graph.adjlist[u].first_edge;
	while(p){
		int v = p->adj_vertex;
		if(!visited[v])
			dfs_graph( graph, v, visited, visit );
		p = p->next;
	}

	return OK;
}

// 广度优先遍历
Status bfs_graph(ALGraph& graph, int u, int* visited, callback visit){
	if( u < 1 || !visited || !visit ){
		std::cerr << "Invalid arguments!";
		return ERROR;
	}

	std::queue<int> que;
	visit( graph, u );
	visited[u] = 1;
	que.push(u);

	while( !que.empty() ){
		u = que.front();
		que.pop();

		EdgeNode* p = graph.adjlist[u].first_edge;
		while( p ){
			int v = p->adj_vertex;
			if(!visited[v]){
				visit( graph, v );
				visited[v] = 1;
				que.push( v );
			}
			p = p->next;
		}
	}

	return OK;
}