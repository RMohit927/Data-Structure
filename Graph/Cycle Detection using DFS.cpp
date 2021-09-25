#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl "\n"
#define f_input freopen("inputs/input.txt", "r", stdin)
#define f_output freopen("inputs/output.txt", "w", stdout)

#define VI vector<int>
#define pb push_back
#define PII pair<int, int>

class Solution{
public:
	bool FindCycleInGraph(int v, VI adj[]){
		VI visited(v+1, 0);
		for (int i = 1; i <= v; i++)
		{
			if(!visited[i]){
				stack<PII> s;
				
				s.push({i, -1});
				visited[i] = true;
				//~ cout << i << " ";
				while(!s.empty()){
					int node = s.top().first;
					int parent = s.top().second;
					s.pop();
					
					for(auto it: adj[node]){
						if(!visited[it]){
							s.push({it, node});
							visited[it] = true;
							//~ cout << it << " ";
						}else if(parent != it){
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
