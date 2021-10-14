#include <bits/stdc++.h>
using namespace std;

const int MAX = 302;
int S, E;

struct Edge
{
    int from, to, c, f;
    Edge *dual;
    Edge(int fr1, int to1, int c1) : from(fr1), to(to1), c(c1), f(0), dual(nullptr) {}

    // 남아 있는 유량
    int spare(){
        return c - f;
    }

    // 플로우를 보낸다.
    void addFlow(int f1){
        f += f1;
        dual->f -= f1;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin >> k;
    while(k--) {
        vector<Edge*> adj[MAX];
        vector<Edge*> chk;
        int n, m;

        cin >> n >> m;
        S = 1;
        E = n;

        for(int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            Edge* e1 = new Edge(u, v,w); Edge* e2 = new Edge(v, u,0);
            e1->dual = e2; e2->dual = e1;
            adj[u].push_back(e1);
            adj[v].push_back(e2);
            chk.push_back(e1);
        }

        // 최대 유량을 모두 채운다.
        while (1)
        {
            int prev[MAX];
            Edge *path[MAX] = {0}; // 경로상의 간선들을 저장해두어 나중에 참조
            fill(prev, prev + MAX, -1);
            queue<int> Q;
            Q.push(S);
            while (!Q.empty() && prev[E] == -1)
            {
                int curr = Q.front();
                Q.pop();
                for (int i = 0; i < adj[curr].size(); i++){
                    Edge *e = adj[curr][i];
                    int next = e->to;
                    if (e->spare() > 0 && prev[next] == -1)
                    {
                        Q.push(next);
                        prev[next] = curr;
                        path[next] = e;
                        if (next == E)
                            break;
                    }
                }
            }
            if (prev[E] == -1)
                break;

            int flow = INT_MAX;
            for (int i = E; i != S; i = prev[i])
                flow = min(flow, path[i]->spare());
            for (int i = E; i != S; i = prev[i])
                path[i]->addFlow(flow);
        }

        // 포화 간선을 찾는다.
        int ans = 0;
        for(int i = 0; i < chk.size(); i++) {
            Edge *e = chk[i];
            int U = e->from;
            int V = e->to;

            // 포화 간선 이라면
            if (e->spare() == 0){
                int prev[MAX];
                Edge *path[MAX] = {0};
                fill(prev, prev + MAX, -1);
                queue<int> Q;
                Q.push(U);
                while (!Q.empty() && prev[V] == -1)
                {
                    int curr = Q.front();
                    Q.pop();
                    for (int i = 0; i < adj[curr].size(); i++)
                    {
                        Edge *e = adj[curr][i];
                        int next = e->to;
                        if (e->spare() > 0 && prev[next] == -1)
                        {
                            Q.push(next);
                            prev[next] = curr;
                            path[next] = e;
                            if (next == V) break;
                        }
                    }
                }
                if(prev[V] == -1) ans++;
            }
        }

        cout << ans << endl;
    }
}