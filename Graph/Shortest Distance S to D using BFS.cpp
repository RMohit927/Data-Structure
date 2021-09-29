#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl "\n"
#define f_input freopen("inputs/input.txt", "r", stdin)
#define f_output freopen("inputs/output.txt", "w", stdout)

#define VI vector<int>
#define pb push_back

class Graph{
	int n;
	VI *adj;
public:
	Graph(int v){
		n = v;
		adj = new VI[v];
	}
	void addEdge(int i, int j, bool unidir = true){
		adj[i].pb(j);
		if(unidir){
			adj[j].pb(i);
		}
	}
	void PrintAdjList(){
		for (int i = 0; i < n; i++) {
			cout << i << " --> ";
			for (auto it: adj[i]) cout << it << ", ";
			cout << endl;
		}
	}
	void bfs(int source){
		queue<int> q;
		VI vis(n, 0);
		VI dist(n, 0);
		VI parent(n, -1);
		
		q.push(source);
		vis[source] = 1;
		parent[source] = source;
		dist[source] = 0;
		
		while(!q.empty()){
			int temp = q.front();
			cout << temp << ", ";
			q.pop();
			
			for (auto nbr: adj[temp]){
				if(!vis[nbr]){
					q.push(nbr);
					parent[nbr] = temp;
					dist[nbr] = dist[temp] + 1;
					vis[nbr] = 1;
				}
			}
		}
		cout << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "Shortest distance from " << source << " to " << i << " is : " << dist[i] << endl;
		}
	}
};

int main(){
	fast;
#ifndef ONLINE_JUDGE
	f_input;
	//~ f_output;
#endif

	int n, m;
	cin >> n >> m;
	Graph g(n);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		g.addEdge(u, v);
	}
	
	g.PrintAdjList();
	
	g.bfs(6);
	return 0;
}
