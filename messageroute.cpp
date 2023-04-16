#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> dis(n + 1, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 1});
    vector<int> parent(n + 1);
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }
    while (!pq.empty())
    {
        int node = pq.top().second;
        int wt = pq.top().first;
        pq.pop();
        if (node == n)
        {
            break;
        }
        for (auto it : adj[node])
        {
            if (wt + 1 < dis[it])
            {
                dis[it] = wt + 1;
                parent[it] = node;
                pq.push({wt + 1, it});
            }
        }
    }

    if (dis[n] == 1e9)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        cout << dis[n]+1 << endl;
        vector<int> ans;
        int a = n;
        while (a != 1)
        {
            ans.push_back(a);
            a = parent[a];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}
