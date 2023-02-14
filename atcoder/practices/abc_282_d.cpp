#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

ll N, M;
vector<int> G[200005];
int colors[200005] = {0,};

P dfs(int node, int p, int color) {
    P res = P(0,0);
    colors[node] = color;

    if(color == 1) res.first++;
    else res.second++;

    for(auto nxt : G[node]) {
        if(nxt == p || colors[nxt] == -color) continue;
        if(colors[nxt] == color) return P(-1, -1);
        P ret = dfs(nxt, node, -color);
        if(ret.first == -1) return P(-1, -1);
        res.first += ret.first;
        res.second += ret.second;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    ll ans = N * (N-1) / 2 - M;
    for(int i = 1; i <= N; i++) {
        if(!colors[i]) {
            P res = dfs(i, -1, 1);
            if(res.first == -1) {
                cout << 0 << endl;
                return 0;
            }

            ans -= res.first * (res.first-1) / 2;
            ans -= res.second * (res.second-1) / 2;
        }
    }

    cout << ans << endl;
    return 0;
}