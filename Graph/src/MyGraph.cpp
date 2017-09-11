#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdint.h>
#include "MyGraph.h"
#include "UnionFindSet.h" 
#define LOCAL

// �������빹��ͼ
Status create_graph( MyGraph& graph ){
#ifdef LOCAL
	std::ifstream cin( "input_copy.dat" );
#endif
	int u, v, c;
	while( cin >> u >> v >> c ){
		
		EdgeNode edge(v, c);
		graph[u].push_back(edge);

		// �˴������������ͼ
		EdgeNode edge1(u, c);
		graph[v].push_back(edge1);
	}
#ifdef LOCAL
	cin.close();
#endif
	return OK;
}

// ���ͼ��Ϣ
Status show_graph( MyGraph& graph ){
	int n = graph.size() - 1;

	// �ڵ��±��1-n
	for( int u = 1; u <= n; ++u ){
		int sz = graph[u].size();
		std::cout << u;
		for( int v = 0; v < sz; ++v ) 
			std::cout << "->" << graph[u][v].adj_vertex;
		std::cout <<std::endl;
	}
	return OK;
}

// ������ȱ���
// ����û�д洢�ڵ���Ϣ�����Է��ʲ���Ϊ����ڵ��±�
Status dfs_graph( MyGraph& graph, int u ){
	if( u < 1 ){
		std::cerr << "Invalid arguments!";
		return ERROR;
	}

	std::vector<int> visited( graph.size(), 0 );
	dfs_graph_helper( graph, u, visited );

	return OK;
}

// ������ȱ���
// ����û�д洢�ڵ���Ϣ�����Է��ʲ���Ϊ����ڵ��±�
Status bfs_graph( MyGraph& graph, int u ){
	if( u < 1 ){
		std::cerr << "Invalid arguments!";
		return ERROR;
	}

	std::vector<int> visited( graph.size(), 0 );
	bfs_graph_helper( graph, u, visited );
	
	return OK;
}

// ������ȱ�����������
Status dfs_graph_helper( MyGraph& graph, int u, std::vector<int>& visited ){
	if( u < 1 ){
		std::cerr << "Invalid arguments.";
		return ERROR;
	}
	
	std::cout << u << " ";
	visited[u] = 1;

	int sz = graph[u].size();
	for( int v = 0; v < sz; ++v ){
		int adj = graph[u][v].adj_vertex;
		if( !visited[adj] )
			dfs_graph_helper( graph, adj, visited );
	}

	return OK;
}

// ������ȱ�����������
Status bfs_graph_helper( MyGraph& graph, int u, std::vector<int>& visited ){
	if( u < 1 ){
		std::cerr << "Invalid arguments.";
		return ERROR;
	}

	std::cout << u << " ";
	visited[u] = 1;

	std::queue<int> que;
	que.push(u);

	while( !que.empty() ){
		u = que.front();
		que.pop();

		int sz = graph[u].size();
		for( int v = 0; v < sz; ++v ){
			int adj = graph[u][v].adj_vertex;
			if( !visited[adj] ){
				std::cout << adj << " ";
				visited[adj] = 1;
				que.push(adj);
			}
		}
	}

	return OK;
}

// �����ͨ�������� 
int get_connected_num( MyGraph& graph ){

	int sz = graph.size();
	int* tree = new int[sz];
	make_set( tree, sz-1 );
	for( int u = 1; u < sz; ++u){
		int sz = graph[u].size();
		for( int i = 0; i < sz; ++i ){
			int v = graph[u][i].adj_vertex;
			union_set( tree, u, v );
		}
	}

	int ans = 0;
	for( int i = 1; i < sz; ++i ){
		if( -1 == tree[i] ) ++ans;
	}
	delete [] tree;
	return ans;
}

// �����С������Ȩֵ
int kruskal( MyGraph& graph ){
	
	int n = graph.size() -1;
	int* tree = new int[n+1];
	make_set( tree, n );
	
	std::vector< Edge > edge_list;
	
	for( int u = 1; u <= n; ++u ){
		int sz = graph[u].size();
		for( int i = 0; i < sz; ++i ){
			int v = graph[u][i].adj_vertex;
			int c = graph[u][i].cost;
			Edge edge( u, v, c );
			edge_list.push_back( edge );
		}
	}

	int ans = 0;
	
	// sort the edge list
	std::sort( edge_list.begin(), edge_list.end() );

	// iterate the edge
	// if u and v are not in the same set, (u, v) is an edge of MST.
	int sz = edge_list.size();
	for( int i = 0; i < sz; ++i ){
		int u = edge_list[i].u;
		int v = edge_list[i].v;
		int c = edge_list[i].c;
		if( union_set( tree, u, v ) ){
			ans += c;
		}
	}

	delete [] tree;
	return ans;
}

// Dijkstra
// ��Դ��s�����е����̾���
std::vector<int> dijkstra( MyGraph& graph, int s ){
	int n = graph.size() - 1;
	std::vector<int> d(n+1, 0); // shortest path estimate from s to i
	std::vector<int> flag(n+1, 0);

	for( int i = 1; i <= n; ++i ){
		d[i] = INT_MAX;
	}
	d[s] = 0;

	int cnt = n;
	while( cnt-- ){
		// select u
		int u = -1;
		int min_edge = INT_MAX;
		for( int i = 1; i <= n; ++i ){
			if( flag[i] ) continue;
			else{
				if( d[i] < min_edge ){
					u = i;
					min_edge = d[i];
				}
			}
		}

		// add u to s
		flag[u] = 1;

		// relax (u,v,w)
		int sz = graph[u].size();
		for( int j = 0; j < sz; ++j ){
			int v = graph[u][j].adj_vertex;
			int w = graph[u][j].cost;
			if( d[u] + w < d[v] )
				d[v] = d[u] + w;
		}
	}
	return d;
}

// Dijkstra
// ��Դ��s��Ŀ���t����̾���
int dijkstra( MyGraph& graph, int s, int t ){
	int n = graph.size() - 1;
	std::vector<int> d(n+1, 0);
	std::vector<int> flag(n+1, 0);

	for( int i = 1; i <= n; ++i ){
		d[i] = INT_MAX;
	}
	d[s] = 0;

	int ans = 0;
	int cnt = n;
	while( cnt-- ){
		// select u
		int u = -1;
		int min_edge = INT_MAX;
		for( int i = 1; i <= n; ++i ){
			if( flag[i] ) continue;
			else{
				if( d[i] < min_edge ){
					min_edge = d[i];
					u = i;
				}
			}
		}

		// add u to s
		flag[u] = 1;
		if( u == t ){
			ans = d[t];
			break;
		}

		// relax(u, v, w)
		int sz = graph[u].size();
		for( int j = 0; j < sz; ++j ){
			int v = graph[u][j].adj_vertex;
			int w = graph[u][j].cost;
			if( d[u] + w < d[v] )
				d[v] = d[u] + w;
		}
	}// while

	return ans;
}

// Bellman-ford
// ��Դ��s�����е����̾���
bool bellman_ford( MyGraph& graph, int s, std::vector<int>& d ){
	int n = graph.size() - 1;

	// init
	for( int i = 1; i <= n; ++i ){
		d[i] = INT_MAX;
	}
	d[s] = 0;

	// V-1 pass
	for( int k = 1; k < n; ++k ){
		// relax each edge
		for( int u = 1; u <= n; ++u ){
			int sz = graph[u].size();
			for( int j = 0; j < sz; ++j ){
				int v = graph[u][j].adj_vertex;
				int w = graph[u][j].cost;
				if( d[u] + w < d[v] )
					d[v] = d[u] + w;
			}
		}
	}

	// test negative cycle
	for( int u = 1; u <= n; ++u ){
		int sz = graph[u].size();
		for( int j = 0; j < sz; ++j ){
			int v = graph[u][j].adj_vertex;
			int w = graph[u][j].cost;
			if( d[u] + w < d[v] )
				return false;
		}
	}

	return true;
}

// Bellman-ford
// ��Դ��s��Ŀ���t����̾���
bool bellman_ford( MyGraph& graph, int s, int t, int& ans ){
	int n = graph.size() - 1;
	std::vector<int> d(n+1, 0);

	// init
	for( int i = 1; i <= n; ++i ){
		d[i] = INT_MAX;
	}
	d[s] = 0;

	// V-1 pass
	for( int k = 1; k < n; ++k ){
		// relax each edge
		for( int u = 1; u <= n; ++u ){
			int sz = graph[u].size();
			for( int j = 0; j < sz; ++j ){
				int v = graph[u][j].adj_vertex;
				int w = graph[u][j].cost;
				if( d[u] + w < d[v] )
					d[v] = d[u] + w;
			}
		}
	}

	// test negative cycle
	for( int u = 1; u <= n; ++u ){
		int sz = graph[u].size();
		for( int j = 0; j < sz; ++j ){
			int v = graph[u][j].adj_vertex;
			int w = graph[u][j].cost;
			if( d[u] + w < d[v] )
				return false;
		}
	}

	ans = d[t];
	return true;
}

// Spfa
// ��Դ��s�����е����̾���
bool spfa( MyGraph& graph, int s, std::vector<int>& d ){
	int n = graph.size() - 1;
	std::vector<int> visited(n+1, 0); // in the queue or not
	std::vector<int> count(n+1, 0);   // number of que.push of u
	std::queue<int> que;

	// init
	for( int i = 1; i <= n; ++i ){
		d[i] = INT_MAX;
	}
	d[s] = 0;

	que.push( s );
	visited[s] = 1;
	count[s] += 1;

	while( !que.empty() ){
		int u = que.front();
		que.pop();
		visited[u] = 0;

		int sz = graph[u].size();
		for( int k = 0; k < sz; ++k ){
			int v = graph[u][k].adj_vertex;
			int w = graph[u][k].cost;

			if( d[u] + w < d[v] ){
				d[v] = d[u] + w;
				if( !visited[v] ){
					que.push(v);
					visited[v] = 1;
					count[v] += 1;

					if( count[v] > n-1 )
						return false;
				}
			}
		}
	}
	return true;
}

// Spfa
// ��Դ��s��Ŀ���t����̾���
bool spfa( MyGraph& graph, int s, int t, int& ans ){
	int n = graph.size() - 1;
	std::vector<int> d(n+1, 0);
	std::vector<int> visited(n+1, 0);
	std::vector<int> count(n+1, 0);
	std::queue<int> que;

	// init
	for( int i = 1; i <= n; ++i ){
		d[i] = INT_MAX;
	}
	d[s] = 0;

	que.push( s );
	visited[s] = 1;
	count[s] += 1;

	while( !que.empty() ){
		int u = que.front();
		que.pop();
		visited[u] = 0;

		int sz = graph[u].size();
		for( int k = 0; k < sz; ++k ){
			int v = graph[u][k].adj_vertex;
			int w = graph[u][k].cost;

			if( d[u] + w < d[v] ){
				d[v] = d[u] + w;
				if( !visited[v] ){
					que.push(v);
					visited[v] = 1;
					count[v] += 1;

					if( count[v] > n-1 )
						return false;
				}
			}
		}
	}
	ans = d[t];
	return true;
}

// TopSort
// ���ͼ���������У�Ҳ�������ж��Ƿ���ڻ�
bool top_sort( MyGraph& graph, std::vector<int>& ans ){
	int n = graph.size() - 1;
	std::vector<int> indegree(n+1, 0);

	for( int u = 1; u <= n; ++u ){
		int sz = graph[u].size();
		for( int k = 0; k < sz; ++k ){
			int v = graph[u][k].adj_vertex;
			++indegree[v];
		}
	}

	std::queue<int> q;
	for( int i = 1; i <= n; ++i ){
		if( !indegree[i] ) q.push(i);
	}

	int cnt = 0;
	while( !q.empty() ){
		int u = q.front();
		q.pop();
		++cnt;
		ans.push_back( u );
		
		int sz = graph[u].size();
		for( int k = 0; k < sz; ++k ){
			int v = graph[u][k].adj_vertex;
			--indegree[v];
			if( !indegree[v] ) q.push(v);
		}
	}

	if( cnt == n ) return true;
	else return false;
}