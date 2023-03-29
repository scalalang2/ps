#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m, s, e;
const int maxn = 51;

ll earn[maxn];
ll dist[maxn];
vector<pair<ll,ll>> adj[maxn];
queue<ll> q;
bool visited[maxn] = {false,};

bool bfs() {
    while(!q.empty()) {
        ll curr = q.front();
        q.pop();

        if(curr == e) return true;
        visited[curr] = true;

        for(auto ee : adj[curr]) {
            ll next = ee.first;
            if(!visited[next]) {
                q.push(next);
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> s >> e >> m;
    while(m--) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
    }

    for(int i = 0; i < n; i++) {
        cin >> earn[i];
    }

    fill(dist, dist + n, INT_MAX);
    dist[s] = -earn[s];

    for(int i = 0; i < n; i++) {
        for(int u = 0; u < n; u++) {
            for(auto ee : adj[u]) {
                ll v = ee.first;
                ll c = ee.second;
                // 거리 = 현재 거리 + 얻는 이익 - 교통비
                if(dist[u] != INT_MAX && dist[v] > dist[u] - earn[v] + c) {
                    dist[v] = dist[u] - earn[v] + c;
                    if(i == n - 1) {
                        q.push(u);
                    }
                }
            }
        }
    }

    if(dist[e] == INT_MAX) {
        cout << "gg";
    } else {
        if(bfs()) cout << "Gee";
        else cout << -dist[e];
    }


    return 0;
}