#include<bits/stdc++.h>

using namespace std;
using pp = pair<int, int>;

const int mxn = 2001;
int n, m, k;
vector<int> G[mxn];
int d[mxn][mxn];
int S[mxn];
int dd[mxn];
int covered[mxn];

void bfs(int node);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    memset(S, 0, sizeof(S));
    memset(dd, -1, sizeof(dd));
    memset(covered, -1, sizeof(covered));

    for(int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    cin >> k;
    while(k--) {
        int node, dist;
        cin >> node >> dist;
        dd[node] = dist;
    }

    for(int i = 1; i <= n; i++) {
        bfs(i);
    }

    for(int i = 1; i <= n; i++) {
        int flag = true;
        for(int j = 1; j <= n; j++) {
            if(dd[j] == -1) continue;
            if(d[i][j] < dd[j]) flag = false;
        }
        if(flag) {
            S[i] = 1;
            for(int j = 1; j <= n; j++) {
                if(d[i][j] == dd[j]) covered[j] = 1;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(covered[i] == -1 && dd[i] != -1) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    for(int i = 1; i <= n; i++) cout << S[i];

    return 0;
}

void bfs(int node) {
    queue<pp> Q = queue<pp>();
    Q.push({node, 0});
    vector<bool> visited(n+1);
    visited[node] = true;

    for(int i = 0; i < n; i++) {
        pp u = Q.front();
        Q.pop();
        for(int v : G[u.first]) {
            if(!visited[v]) {
                visited[v] = true;
                Q.push({v, u.second+1});
                d[node][v] = u.second+1;
            }
        }
    }
}