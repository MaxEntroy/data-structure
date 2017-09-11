#ifndef ALGraph_H
#define ALGraph_H
#include <cstring>
#include "common.h"
#define MAXSIZE 16

// 边表节点
struct EdgeNode{
	int adj_vertex; // 邻接顶点下标
	EdgeNode* next;

	EdgeNode(){ std::memset( this, 0, sizeof(EdgeNode) ); }
	EdgeNode( int adj ) : adj_vertex( adj ) { next = NULL; }
};

// 顶点表节点
struct VertexNode{
	ElemType vertex; // 顶点信息
	EdgeNode* first_edge;

	VertexNode(){ std::memset( this, 0, sizeof(VertexNode) ); }
};

// 邻接表存储结构声明
struct ALGraph{
	VertexNode adjlist[MAXSIZE];
	int vertex_num;
	int edge_num;

	ALGraph(){ std::memset( this, 0, sizeof(ALGraph) ); }
};

typedef Status (*callback)( ALGraph&, int );

// 创建邻接表
Status create_graph( ALGraph& graph, const ElemType* arr, int n, int e );

// 销毁邻接表
Status destroy_graph( ALGraph& graph );

// 输出邻接表
Status show_graph(ALGraph& graph);

// 深度优先遍历
Status dfs_graph(ALGraph& graph, int u, int* visited, callback visit ); // u是遍历起点序号

// 广度优先遍历
Status bfs_graph(ALGraph& graph, int u, int* visited, callback visit);  // u是遍历起点序号


#endif