#include<bits/stdc++.h>

using namespace std;
const int mxn = 300001;
int n, m;
int par[mxn];
int dp[mxn];
vector<int> adj[mxn];

void dfs(int node) {
    if(node > 1) {
        dp[node] = max(dp[node], dp[par[node]] - 1);
    }

    for(auto nxt : adj[node]) {
        dfs(nxt);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;

    memset(dp, -1, sizeof(dp));

    for(int i = 2; i <= n; i++) {
        cin >> par[i];
        adj[par[i]].push_back(i);
    }

    while(m--) {
        int x,y;
        cin >> x >> y;
        dp[x] = max(dp[x], y);
    }

    dfs(1);

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(dp[i] >= 0) ans++;
    }

    cout << ans << endl;
}