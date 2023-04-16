#include<bits/stdc++.h>
using namespace std;

class Disjoint{
    vector<int> parent;
    vector<int> size;

public:
    Disjoint(int n){
        parent.resize(n+1,0);
        size.resize(n+1,0);
        for(int i = 0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findPar(int u){
        if(parent[u] == u){
            return u;
        }
        return parent[u] = findPar(parent[u]);
    }

    void merge(int u, int v) {
        int upu = findPar(u);
        int upv = findPar(v);
        if (upu == upv) return;
        if (size[upu] < size[upv]) {
            parent[upu] = upv;
            size[upv] += size[upu];
        }
        else {
            parent[upv] = upu;
            size[upu] += size[upv];
        }
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    Disjoint ds(n);
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        ds.merge(a,b);
    }
    vector<pair<int,int>> vec;
    for(int i = 1;i<n;i++){
        if(ds.findPar(i)!=ds.findPar(i+1)){
            vec.push_back({i,i+1});
            ds.merge(i,i+1);
        }
    }
    cout<<vec.size()<<endl;
    for(auto it:vec){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}

