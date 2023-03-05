#include<bits/stdc++.h>

using namespace std;

int n, m, ans;
const int maxn = 2001;
vector<int> G[maxn];
int adj[maxn][maxn];
bool visited[maxn];

void dfs(int curr, int p) {
    visited[curr] = true;
    for(auto nxt : G[curr]) {
        if(visited[nxt]) continue;
        if(p != -1) {
            if(adj[p][curr] == 1 && adj[curr][nxt] == 1 && adj[p][nxt] == 0){
                ans++;
                adj[p][nxt] = 1;
                G[p].push_back(nxt);
                dfs(nxt, p);
            }
        }
        dfs(nxt, curr);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ans = 0;

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        adj[u][v] = 1;
    }

    for(int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        dfs(i, -1);
    }

    cout << ans << endl;
    return 0;
}