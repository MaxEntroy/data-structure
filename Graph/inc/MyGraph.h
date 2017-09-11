#ifndef MyGraph_H
#define MyGraph_H
#include <vector>
#include <cstring>
#include "common.h"

// 边结构定义
// 这种结构主要用在kruskal算法当中，图表示为边的集合
// 这种表示方法无法进行遍历操作，只能用在特殊场合
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

//我用二维vector实现的一个邻接表
//由于不存储节点信息，所以邻接表中只存EdgeNode
//节点信息暂时用下表代替，不存储节点数量以及边数量
//这种数据结构在刷题的时候比较方便，这类问题的节点内容一般可以用下标代替
//如果需要存储特定的节点信息，还是使用之前的两种规范定义

// 边表节点结构声明
struct EdgeNode{
	int adj_vertex;
	int cost;
	EdgeNode(){ std::memset( this, 0, sizeof(EdgeNode) ); }
	EdgeNode( int adj, int c ) : adj_vertex(adj) , cost(c) {}
};

// 边表类型定义
typedef std::vector< EdgeNode > EdgeList; 

// 邻接表类型定义
// 创建的时候需要指定维度，eg: MyGraph graph(8); 
// 维度至少应该是节点的最大编号+1
typedef std::vector< EdgeList > MyGraph;  


// 根据输入构建图
Status create_graph( MyGraph& graph );

// 输出图信息
Status show_graph( MyGraph& graph );

// 深度优先遍历
// 由于没有存储节点信息，所以访问操作为输出节点下标
Status dfs_graph( MyGraph& graph, int u );

// 广度优先遍历
// 由于没有存储节点信息，所以访问操作为输出节点下标
Status bfs_graph( MyGraph& graph, int v );

// 深度优先遍历辅助函数
Status dfs_graph_helper( MyGraph& graph, int u, std::vector<int>& visited );

// 广度优先遍历辅助函数
Status bfs_graph_helper( MyGraph& graph, int u, std::vector<int>& visited );

// 获得联通分量个数
int get_connected_num( MyGraph& graph );

// 获得最小生成树权值
int kruskal( MyGraph& graph );

// Dijkstra
// 单源点s到所有点的最短距离
std::vector<int> dijkstra( MyGraph& graph, int s );

// Dijkstra
// 单源点s到目标点t的最短距离
int dijkstra( MyGraph& graph, int s, int t );

// Bellman-ford
// 单源点s到所有点的最短距离
bool bellman_ford( MyGraph& graph, int s, std::vector<int>& d );

// Bellman-ford
// 单源点s到目标点t的最短距离
bool bellman_ford( MyGraph& graph, int s, int t, int& ans );

// Spfa
// 单源点s到所有点的最短距离
bool spfa( MyGraph& graph, int s, std::vector<int>& d );

// Spfa
// 单源点s到目标点t的最短距离
bool spfa( MyGraph& graph, int s, int t, int& ans );

// TopSort
// 获得图的拓扑序列，也可用来判断是否存在环
bool top_sort( MyGraph& graph, std::vector<int>& ans );

#endif