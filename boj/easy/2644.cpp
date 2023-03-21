#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, a, b, m;
    cin >> n >> a >> b >> m;

    vector<vector<int>> G(n+1);
    while(m--) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int ans = -1;
    queue<pair<int, int>> Q;
    Q.push(make_pair(a, 0));
    vector<bool> visited(n+1, false);

    visited[a] = true;
    while(!Q.empty()) {
        pair<int,int> curr = Q.front(); Q.pop();
        if(curr.first == b) {
            ans = curr.second;
            break;
        }

        for(auto nxt : G[curr.first]) {
            if(visited[nxt]) continue;
            visited[nxt] = true;
            Q.push(make_pair(nxt, curr.second+1));
        }
    }

    cout << ans << endl;



    return 0;
}