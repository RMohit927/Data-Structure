#include<bits/stdc++.h>
using namespace std;

// Vector
#define VI vector<int>
#define pb push_back

// File handling
#define f_input freopen("inputs/input.txt", "r", stdin)
#define f_output freopen("inputs/output.txt", "w", stdout)
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)

class Solution{
public:
	VI dfsOfGraph(int v, VI adj[]){
		VI visited(v+1, 0);
		VI dfs;
		for (int i = 1; i <= v; i++)
		{
			if(!visited[i]){
				stack<int> stk;
				stk.push(i);
				visited[i] = 1;
				while(!stk.empty()){
					int temp = stk.top();
					stk.pop();
					dfs.pb(temp);
					for(auto it: adj[temp]){
						if(!visited[it]){
							stk.push(it);
							visited[it] = 1;
						}
					}
				}
			}
		}
		return dfs;
	}
};

int main(){
	fast;
#ifndef ONLINE_JUDGE
	f_input;
	f_output;
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
	VI result = obj.dfsOfGraph(n, adj);
	
	for (auto it: result)
	{
		cout << it << " ";
	}
	
	return 0;
}

/*
 * Complexity: O(V + E)
 * 
 * Adjacency list: 
 * 	1 => [2, 3]
 * 	2 => [1, 4, 5]
 * 	3 => [1]
 * 	4 => [2]
 * 	5 => [2]
 * 
 * visited: [ , , , , ]
 * Ans: 1 - 2 - 4 - 5 - 3
 */
