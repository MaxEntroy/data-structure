#ifndef MGraph_H
#define MGraph_H

#include <cstring>
#include "common.h"

#define MAXSIZE 16
#define UNDIRECTED

// 邻接矩阵存储结构声明
struct MGraph{
	int vertex_num; // 节点数
	int edge_num; // 边数
	ElemType vertex[MAXSIZE]; // 顶点信息
	int arc[MAXSIZE][MAXSIZE];// 边信息
	
	MGraph(){ std::memset( this, 0, sizeof(MGraph) ); };
};

typedef Status (*callback)(MGraph&, int);

// 创建邻接矩阵
Status create_graph( MGraph& graph, const ElemType* arr, int n, int e );

// 输出邻接矩阵
Status show_graph(MGraph& graph);

// 深度优先遍历
Status dfs_graph(MGraph& graph, int u, int* visited, callback visit ); // u是遍历起点序号

// 广度优先遍历
Status bfs_graph(MGraph& graph, int u, int* visited, callback visit);  // u是遍历起点序号
#endif