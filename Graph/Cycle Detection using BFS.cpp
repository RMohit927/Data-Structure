#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl "\n"
#define f_input freopen("inputs/input.txt", "r", stdin)
#define f_output freopen("inputs/output.txt", "w", stdout)

#define VI vector<int>
#define PII pair<int, int>
#define pb push_back

class Solution{
public:
	bool FindCycleInGraph(int v, VI adj[]){
		VI visited(v+1, 0);
		for (int i = 1; i <= v; i++)
		{
			if(!visited[i]){
				queue<PII> q;
				
				visited[i] = true;
				q.push({i, -1});
				
				while(!q.empty()){
					int node = q.front().first;
					int parent = q.front().second;
					q.pop();
					for(auto it: adj[node]){
						if(!visited[it]){
							visited[it] = true;
							q.push({it, node}); // (node, parent)
						} else if(parent != it){
							return true;
						}
					}
				}
			}
		}
		return false;
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
	VI adj[n+1];
	for (int i = 0; i < m; i++)
	{
		int v, u;
		cin >> v >> u;
		adj[v].pb(u);
		adj[u].pb(v);
	}
	Solution obj;
	bool result = obj.FindCycleInGraph(n, adj);
	if(result)
		cout << "Graph Contains Cycle!" << endl;
	else
		cout << "Graph does not Contains Cycle!" << endl;
	
	return 0;
}

/*
 * Complexity: O(N + E)
 *
 */
