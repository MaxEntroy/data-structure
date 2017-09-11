#ifndef MGraph_H
#define MGraph_H

#include <cstring>
#include "common.h"

#define MAXSIZE 16
#define UNDIRECTED

// �ڽӾ���洢�ṹ����
struct MGraph{
	int vertex_num; // �ڵ���
	int edge_num; // ����
	ElemType vertex[MAXSIZE]; // ������Ϣ
	int arc[MAXSIZE][MAXSIZE];// ����Ϣ
	
	MGraph(){ std::memset( this, 0, sizeof(MGraph) ); };
};

typedef Status (*callback)(MGraph&, int);

// �����ڽӾ���
Status create_graph( MGraph& graph, const ElemType* arr, int n, int e );

// ����ڽӾ���
Status show_graph(MGraph& graph);

// ������ȱ���
Status dfs_graph(MGraph& graph, int u, int* visited, callback visit ); // u�Ǳ���������

// ������ȱ���
Status bfs_graph(MGraph& graph, int u, int* visited, callback visit);  // u�Ǳ���������
#endif