#ifndef MyGraph_H
#define MyGraph_H
#include <vector>
#include <cstring>
#include "common.h"

// �߽ṹ����
// ���ֽṹ��Ҫ����kruskal�㷨���У�ͼ��ʾΪ�ߵļ���
// ���ֱ�ʾ�����޷����б���������ֻ���������ⳡ��
struct Edge{
	int u;
	int v;
	int c;
	Edge(){u = 0; v = 0; c = 0;}
	Edge( int uu, int vv, int cc ) : u(uu), v(vv), c(cc) {}
	bool operator<( const Edge& rhs ) const {
		return c < rhs.c;
	}
};

//���ö�άvectorʵ�ֵ�һ���ڽӱ�
//���ڲ��洢�ڵ���Ϣ�������ڽӱ���ֻ��EdgeNode
//�ڵ���Ϣ��ʱ���±���棬���洢�ڵ������Լ�������
//�������ݽṹ��ˢ���ʱ��ȽϷ��㣬��������Ľڵ�����һ��������±����
//�����Ҫ�洢�ض��Ľڵ���Ϣ������ʹ��֮ǰ�����ֹ淶����

// �߱�ڵ�ṹ����
struct EdgeNode{
	int adj_vertex;
	int cost;
	EdgeNode(){ std::memset( this, 0, sizeof(EdgeNode) ); }
	EdgeNode( int adj, int c ) : adj_vertex(adj) , cost(c) {}
};

// �߱����Ͷ���
typedef std::vector< EdgeNode > EdgeList; 

// �ڽӱ����Ͷ���
// ������ʱ����Ҫָ��ά�ȣ�eg: MyGraph graph(8); 
// ά������Ӧ���ǽڵ�������+1
typedef std::vector< EdgeList > MyGraph;  


// �������빹��ͼ
Status create_graph( MyGraph& graph );

// ���ͼ��Ϣ
Status show_graph( MyGraph& graph );

// ������ȱ���
// ����û�д洢�ڵ���Ϣ�����Է��ʲ���Ϊ����ڵ��±�
Status dfs_graph( MyGraph& graph, int u );

// ������ȱ���
// ����û�д洢�ڵ���Ϣ�����Է��ʲ���Ϊ����ڵ��±�
Status bfs_graph( MyGraph& graph, int v );

// ������ȱ�����������
Status dfs_graph_helper( MyGraph& graph, int u, std::vector<int>& visited );

// ������ȱ�����������
Status bfs_graph_helper( MyGraph& graph, int u, std::vector<int>& visited );

// �����ͨ��������
int get_connected_num( MyGraph& graph );

// �����С������Ȩֵ
int kruskal( MyGraph& graph );

// Dijkstra
// ��Դ��s�����е����̾���
std::vector<int> dijkstra( MyGraph& graph, int s );

// Dijkstra
// ��Դ��s��Ŀ���t����̾���
int dijkstra( MyGraph& graph, int s, int t );

// Bellman-ford
// ��Դ��s�����е����̾���
bool bellman_ford( MyGraph& graph, int s, std::vector<int>& d );

// Bellman-ford
// ��Դ��s��Ŀ���t����̾���
bool bellman_ford( MyGraph& graph, int s, int t, int& ans );

// Spfa
// ��Դ��s�����е����̾���
bool spfa( MyGraph& graph, int s, std::vector<int>& d );

// Spfa
// ��Դ��s��Ŀ���t����̾���
bool spfa( MyGraph& graph, int s, int t, int& ans );

// TopSort
// ���ͼ���������У�Ҳ�������ж��Ƿ���ڻ�
bool top_sort( MyGraph& graph, std::vector<int>& ans );

#endif