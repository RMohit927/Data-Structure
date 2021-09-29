#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl "\n"
#define VI vector<int>
#define pb push_back

class Solution{
public:
	vector<int> bfsOfGraph(int v, VI adj[]){
		VI bfs;
		VI visited(v+1, 0);
		for (int i = 1; i <= v; i++)
		{
			if(!visited[i]){
				queue<int> q;
				q.push(i);
				visited[i] = 1;
				while(!q.empty()){
					int temp = q.front();
					q.pop();
					bfs.pb(temp);
					
					for(auto it: adj[temp]){
						if(!visited[it]){
							q.push(it);
							visited[it] = 1;
						}
					}
				}
			}
		}
		return bfs;
	}
};

int main(){
	fast;
	int n, m;
	cin >> n >> m;
	VI adj[n+1];
	for (int i = 0; i < m; i++)
	{
		int u,v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	Solution obj;
	VI result = obj.bfsOfGraph(n, adj);
	for(int it: result){
		cout << it << " ";
	}
	return 0;
}

/*
 * We have been using Adjacency List
 * Complexity: O(V + E)
 * 
 * /


/* Approach 2: */

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
		
		q.push(source);
		vis[source] = 1;
		
		while(!q.empty()){
			int temp = q.front();
			q.pop();
			cout << temp << " ";
			
			for (auto it: adj[temp])
			{
				if(!vis[it]){
					q.push(it);
					vis[it] = 1;
				}
			}		
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
	
	g.bfs(1);
	return 0;
}
