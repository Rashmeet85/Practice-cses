#include <bits/stdc++.h>
using namespace std;

#define int long long int

bool dfs(vector<int> adj[], int node, vector<int> &vis, vector<int> &pathvis, vector<int> &parent, vector<int> &path) {
    vis[node] = 1;
    pathvis[node] = 1;
    path.push_back(node);
    for (auto it : adj[node]) {
        parent[it] = node;
        if (!vis[it]) {
            if (dfs(adj, it, vis, pathvis, parent, path)) {
                return true;
            }
        }
        else if (pathvis[it]) {
            path.push_back(it);
           
            int idx = find(path.begin(), path.end(), it) - path.begin();
             cout<<path.size() - idx<<endl;
            for (int i = idx; i < path.size(); i++) {
                cout << path[i] << " ";
            }
            cout << endl;
            return true;
        }
    }
    path.pop_back();
    pathvis[node] = 0;
    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }   

    vector<int> vis(n+1, 0);
    vector<int> pathvis(n+1, 0);
    vector<int> parent(n+1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    bool isfound = false;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vector<int> path;
            if (dfs(adj, i, vis, pathvis, parent, path)) {
                isfound = true;
                return 0;
            }
        }
    }
    if(isfound == false) cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
