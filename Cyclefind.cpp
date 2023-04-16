#include<bits/stdc++.h>
using namespace std;
#define int long long int
void bellman_ford(int n,int m,vector<pair<int,pair<int,int>>> &edges){
	vector<int> dist(n+1);
	vector<int> parent(n+1,-1);
	dist[1] = 0;
	int x ;
	for(int i = 1;i<=n;i++){
		x = -1;
		for(auto it:edges){
			int node = it.first;
			int anode = it.second.first;
			int wt = it.second.second;
			if(dist[node] + wt<dist[anode]){
				dist[anode] =  wt + dist[node];
				parent[anode] = node;
				x = anode; 
			}
		//	cout<<x<<" ";
		}
	}
	//cout<<x<<endl;
	//cout<<x<<endl;
	
	if(x == -1){
		cout<<"NO"<<endl;
		return;
	}
	else{
		cout<<"YES"<<endl;
		for(int i = 1;i<=n;i++){
			x = parent[x];
		//	cout<<x<<" ";
		}
		vector<int> ans;
		for(int v = x;; v=parent[v]){
			ans.push_back(v);
			//cout<<v<<" ";
			if(v==x && ans.size()>1){
				break;
			}
		}
		reverse(ans.begin(),ans.end());
		for(auto it:ans){
			cout<<it<<" ";
		}
		//return;
	}
	

}
int32_t main(){
	int n,m;
	cin>>n>>m;
	vector<pair<int,pair<int,int>>> edges(n+1);

	for(int i = 0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		edges.push_back({a,{b,c}});
	}

	bellman_ford(n,m,edges);
	return 0;
}