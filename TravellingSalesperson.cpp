#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int INF = 1e9;
const int MAXN = 12;

int n, t;
int dist[MAXN][MAXN];
int dp[MAXN][1 << MAXN];

int tsp(int cur, int mask) {
    if (mask == (1 << n) - 1) {
        return dist[cur][0];
    }
    if (dp[cur][mask] != -1) {
        return dp[cur][mask];
    }
    int ans = INF;
    for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) == 0) {
            ans = min(ans, dist[cur][i] + tsp(i, mask | (1 << i)));
        }
    }
    return dp[cur][mask] = ans;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> dist[i][j];
            }
        }
        int ans = tsp(0, 1);
        cout << ans << endl;
    }
    return 0;
}
