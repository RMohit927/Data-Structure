#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl "\n"
#define f_input freopen("inputs/input.txt", "r", stdin)
#define f_output freopen("inputs/output.txt", "w", stdout)

typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pli;
typedef pair<ld, ld> pld;

typedef vector<long> VL;
typedef vector<int> VI;
typedef vector<ll> VLLI;
typedef vector<pi> VPI;
typedef vector<pli> VPLI;

#define mk make_pair
#define pb push_back
#define test int t; cin >> t; while(t--)

class Solution{
public:
	string Helper(string s){
		if(s.length() == 1) return to_string(stoi(s) - 1);
		int digit = s.length();
		
		VL candidates;
		candidates.pb(pow(10,digit-1) - 1);
		candidates.pb(pow(10,digit) + 1);
		
		int mid = (digit + 1)/2;
		long prefix = stol(s.substr(0,mid));
		VL v = {prefix, prefix+1, prefix-1};
		
		for (long it: v)
		{
			string postfix = to_string(it);
			if(digit % 2 != 0) postfix.pop_back();
			reverse(postfix.begin(), postfix.end());
			string c = to_string(it) + postfix;
			candidates.pb(stol(c));
		}
		long mindiff = LONG_MAX;
		long result;
		long num = stol(s);
		for(int i = 0; i < 5; i++)
		{
		   if(candidates[i] != num && abs(candidates[i] - num) < mindiff)
		   {
			   mindiff = abs(candidates[i] - num);
			   result = candidates[i];
		   }
		   else if(abs(candidates[i] - num) == mindiff) result = min(result, candidates[i]);
		}
		return to_string(result);
	}
};

int main(){
	fastio;
#ifndef ONLINE_JUDGE
	//~ f_input;
	//~ f_output;
#endif
	
	Solution obj;
	string s;
	cin >> s;
	cout << obj.Helper(s) << endl;
	
	return 0;
}
