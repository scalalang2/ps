#include<bits/stdc++.h>

using namespace std;
using pp = pair<int, int>;

int t;
int n, m;
vector<vector<pp>> adj;
vector<int> dp;

int f(int parent, int node){ 
    if(dp[node] != -1) return dp[node];
    int ret = INT_MAX;
    int sum = 0;
    for(auto child : adj[node]) {
        if(child.first == parent) ret = child.second;
        else {
            if(adj[child.first].size() == 1) sum += child.second;
            else sum += f(node, child.first);
        }
    }
    ret = min(ret, sum);
    dp[node] = ret;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while(t--) {
        cin >> n >> m;
        adj = vector<vector<pp>>(1001, vector<pp>());
        dp = vector<int>(1001, -1);
        while(m--) {
            int u, v, c;
            cin >> u >> v >> c;
            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }

        cout << f(-1, 1) << endl;
    }
    return 0;
}