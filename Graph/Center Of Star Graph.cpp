#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl "\n"
#define f_input freopen("inputs/input.txt", "r", stdin)
#define f_output freopen("inputs/output.txt", "w", stdout)

#define VI vector<int>
#define pb push_back

class Graph{
	int V;
	list<int> *l;
public:
	Graph(int v){
		V = v;
		l = new list<int>[V];
	}
	void addEdge(int i, int j, bool undir=true){
		l[i].pb(j);
		if(undir){
			l[j].pb(i);
		}
	}
	void printAdjList(){
		for (int i = 0; i < V; i++)
		{
			cout << i << " --> ";
			for (int it: l[i])
			{
				cout << it << ", ";
			}
			cout << endl;
		}
	}
	void CenterOfStarGraph(){
		map<int, int> m;
		set<int> s;
		for (int i = 0; i < V; i++)
		{
			for (auto it: l[i])
			{
				m[it]++;
				s.insert(it);
			}
		}
		for (auto it: s)
		{
			if(m[it] == (int)s.size()-1){
				cout << "The Center element of Star Graph is : " << it << endl;
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
	
	g.CenterOfStarGraph();
	
	g.printAdjList();
	return 0;
}
