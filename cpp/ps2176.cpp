#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int node;
    int cost;
};

struct comp {
    inline bool operator()(const Edge &e1, const Edge &e2) {
        return e1.cost > e2.cost;
    }
};

// 모든 정점 X에서 T로 도착하는 최단거리를 계산한다.
int dist[1001][1001];
vector<Edge> adj[1001];
int dp[1001];

int S = 1, T = 2;

void dijkstra(int st) {
    Edge e = {st, 0};

    // priority queue 내부에서는 내림차순 정렬을 해야
    // 가장 작은게 빨리 나온다.
    priority_queue<Edge, vector<Edge>, comp> queue;
    queue.push(e);
    dist[st][st] = 0;

    while(!queue.empty()) {
        Edge e = queue.top();
        queue.pop();
        
        for(int i = 0; i < adj[e.node].size(); i++) {
            Edge nxt = adj[e.node][i];
            if(e.cost + nxt.cost < dist[st][nxt.node]) {
                dist[st][nxt.node] = e.cost + nxt.cost;
                Edge _new = { nxt.node, dist[st][nxt.node] };
                queue.push(_new);
            }
        }
    }
}

int run(int v) {
    if(v == 2) return 1;
    int &ret = dp[v];
    if(ret != -1) {
        return ret;
    }
    ret = 0;

    for(int i = 0; i < adj[v].size(); i++) {
        Edge nxt = adj[v][i];
        if(dist[v][2] > dist[nxt.node][2]) {
            ret += run(nxt.node);
        }
    }
    
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fill(&dist[0][0], &dist[0][0] + 1001 * 1001, INT_MAX);
    fill(dp, dp + 1001, -1);
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int u,v,c;
        cin >> u >> v >> c;
        Edge e1 = {u, c};
        Edge e2 = {v, c};
        adj[u].push_back(e2);
        adj[v].push_back(e1);
    }

    for(int i = 1; i <= n; i++)
        dijkstra(i);

    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= n; j++) {
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << run(1) << endl;
}