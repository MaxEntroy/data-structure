#ifndef ALGraph_H
#define ALGraph_H
#include <cstring>
#include "common.h"
#define MAXSIZE 16

// �߱�ڵ�
struct EdgeNode{
	int adj_vertex; // �ڽӶ����±�
	EdgeNode* next;

	EdgeNode(){ std::memset( this, 0, sizeof(EdgeNode) ); }
	EdgeNode( int adj ) : adj_vertex( adj ) { next = NULL; }
};

// �����ڵ�
struct VertexNode{
	ElemType vertex; // ������Ϣ
	EdgeNode* first_edge;

	VertexNode(){ std::memset( this, 0, sizeof(VertexNode) ); }
};

// �ڽӱ�洢�ṹ����
struct ALGraph{
	VertexNode adjlist[MAXSIZE];
	int vertex_num;
	int edge_num;

	ALGraph(){ std::memset( this, 0, sizeof(ALGraph) ); }
};

typedef Status (*callback)( ALGraph&, int );

// �����ڽӱ�
Status create_graph( ALGraph& graph, const ElemType* arr, int n, int e );

// �����ڽӱ�
Status destroy_graph( ALGraph& graph );

// ����ڽӱ�
Status show_graph(ALGraph& graph);

// ������ȱ���
Status dfs_graph(ALGraph& graph, int u, int* visited, callback visit ); // u�Ǳ���������

// ������ȱ���
Status bfs_graph(ALGraph& graph, int u, int* visited, callback visit);  // u�Ǳ���������


#endif