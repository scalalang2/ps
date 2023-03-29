#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int const maxn = 501;
vector<tuple<ll, ll, ll>> edges;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        ll u,v,c;
        cin >> u >> v >> c;
        edges.push_back({u,v,c});
    }

    ll inf = INT_MAX;
    vector<ll> dist(n+1, inf);
    dist[1] = 0;

    for(int i = 1; i <= n; i++) {
        for(auto e : edges) {
            ll u,v,c;
            tie(u,v,c) = e;
            if(dist[u] != inf && dist[v] > dist[u] + c) {
                dist[v] = dist[u] + c;
                if(i == n) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    for(int i = 2; i <= n; i++) {
        if(dist[i] == inf) cout << -1 << '\n';
        else cout << dist[i] << '\n';
    }

    return 0;
}