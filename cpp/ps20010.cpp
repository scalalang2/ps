// tag - MST
#include <bits/stdc++.h>

using namespace std;

struct PP {
    int from;
    int to;
    int cost;
};

struct P {
    int to;
    int cost;
};

struct comp {
    inline bool operator()(const PP &p1, const PP &p2) {
        return p1.cost < p2.cost;
    }
};

int n, m;
vector<PP> adj;
vector<P> graph[1001];
int pr[1001];
int dist[1001][1001];

int find(int node)
{
    if (pr[node] == node)
        return node;
    else
    {
        pr[node] = find(pr[node]);
        return pr[node];
    }
}

void merge(int a, int b)
{
    int a1 = find(a);
    int b1 = find(b);
    // 서로 다르다고 한다면 b1의 부모를 a1으로 설정한다.
    if (a1 != b1) {
        pr[b1] = a1;
    }
}

void dfs(int st, int node, int cost) {
    for(int i = 0; i < graph[node].size(); i++) {
        P el = graph[node][i];
        int nxt = el.to;
        if (cost + el.cost < dist[st][nxt]) {
            dist[st][nxt] = cost + el.cost;
            dfs(st, nxt, cost + el.cost);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fill(&dist[0][0], &dist[0][0] + 1001 * 1001, INT_MAX);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        pr[u] = u;
        pr[v] = v;
        PP p = { u,v,c };
        adj.push_back(p);
    }

    int total_cost = 0;
    sort(adj.begin(), adj.end(), comp());

    for(int i = 0; i < m; i++) {
        int u = adj[i].from, v = adj[i].to;
        int a = find(u);
        int b = find(v);
        if(a == b) {
            continue;
        }
        merge(u, v);
        P el1 = {v, adj[i].cost};
        P el2 = {u, adj[i].cost};
        graph[u].push_back(el1);
        graph[v].push_back(el2);
        total_cost += adj[i].cost;
    }

    cout << total_cost << endl;
    for(int i = 0; i < n; i++) {
        dfs(i, i, 0);
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (dist[i][j] != INT_MAX && i != j)
                ans = max(dist[i][j], ans);
        }
    }

    cout << ans << endl;


    return 0;
}