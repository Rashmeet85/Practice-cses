#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> vec(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        vec[a].push_back({b, c});
    }

    vector<vector<int>> dist(n + 1, vector<int>(k,9e17));
   // vector<int> count(n + 1, 0);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 1});
    dist[1][0] = 0;
    //count[1] = 1;
    vector<int> ans;
    while (!pq.empty())
    {
        int node = pq.top().second;
        int wt = pq.top().first;
         pq.pop();
        if (dist[node][k-1] <wt) 
            continue;
        
       
        for (auto it : vec[node])
        {
            int adjnode = it.first;
            int awt = it.second;

            if (dist[adjnode][k-1] > (wt + awt) )
            {
                dist[adjnode][k-1] = wt + awt;
               // count[adjnode] += 1;
                pq.push({wt + awt, adjnode});
                sort(dist[adjnode].begin(),dist[adjnode].end());
            }
        }
    }
  //  sort(ans.begin(), ans.end());
    for (int i = 0;i<k;i++)
    {
        cout << dist[n][i] << " ";
    }
    return 0;
}
