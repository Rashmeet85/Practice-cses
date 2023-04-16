#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int INF = 9e17;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> vec(n+1);
    for(int i = 0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        vec[a].push_back({b,c});
    }

    vector<int> dist(n+1, INF);
    vector<int> disc(n+1, INF);
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    pq.push({0,{1,0}});
    while(!pq.empty()){
        int wt = pq.top().first;
        int node = pq.top().second.first;
        int flag = pq.top().second.second;
        pq.pop();
        if(flag == 0){
            if(dist[node]<wt){
                continue;
            }
        }
        if(flag == 1){
            if(disc[node]<wt){
                continue;
            }
        }

        for(auto it:vec[node]){
            int adjnode = it.first;
            int awt = it.second;
            if(flag == 0){
                if(dist[adjnode]>wt + awt){
                    dist[adjnode] = wt + awt;
                    pq.push({dist[adjnode], {adjnode,0}});
                }
                if(disc[adjnode]>wt + awt/2){
                    disc[adjnode] = wt + awt/2;
                    pq.push({disc[adjnode], {adjnode,1}});
                }
            }
            if(flag == 1){
                if(disc[adjnode]>wt + awt){
                    disc[adjnode] = wt + awt;
                    pq.push({disc[adjnode], {adjnode,1}});
                }
            }
        }
    }
    cout<<disc[n]<<endl;
}
