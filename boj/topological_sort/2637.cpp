#include<bits/stdc++.h>

using namespace std;

using ll = long long;

vector<int> G[101];
int in[101];
int out[101];
int cost[101][101];
int dp[101];

int count(int node) {
    int ret = dp[node];
    int a = 0;
    for(auto nxt:G[node]) {
        a += dp[nxt];
    }
    return ret * a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u,v,c;
        cin >> u >> v >> c;
        G[u].push_back(v);
        in[v]++;
        out[u]++;
        cost[u][v] = c;
        cost[v][u] = c;
    }

    queue<int> Q;
    vector<int> basic;
    for(int i = 1; i <= n; i++) {
        if(out[i] == 0) basic.push_back(i);
    }

    Q.push(n);
    dp[n] = 1;
    while(!Q.empty()) {
        int curr = Q.front(); Q.pop();
        for(auto nxt : G[curr]) {
            dp[nxt] += cost[curr][nxt] * dp[curr];
            if(--in[nxt] == 0)
                Q.push(nxt);
        }
    }

    for(int i = 0; i < basic.size(); i++) {
        cout << basic[i] << " " << dp[basic[i]] << endl;
    }

    return 0;
}