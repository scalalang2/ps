#include <bits/stdc++.h>
using namespace std;

const int MAX = 3005;
const int SEC = 2000;
const int JOB = 1000;
const int S = 3003;
const int E = 3004;
const int MEDIUM = 3002;

struct Edge
{
    int from, to, c, f;
    Edge *dual;
    Edge(int fr1, int to1, int c1) : from(fr1), to(to1), c(c1), f(0), dual(nullptr) {}

    // 남아 있는 유량
    int spare() {
        return c - f;
    }

    // 플로우를 보낸다.
    void addFlow(int f1) {
        f += f1;
        dual->f -= f1;
    }
};

vector<Edge *> adj[MAX];

int maxFlow()
{
    // 최대 유량을 모두 채운다.
    int totalFlow = 0;
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
            for (int i = 0; i < adj[curr].size(); i++)
            {
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

        totalFlow += flow;
    }

    return totalFlow;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        int num;
        cin >> num;

        while(num--) {
            int j;
            cin >> j;

            Edge* e1 = new Edge(i, j + JOB, 1);
            Edge* e2 = new Edge(j + JOB, i, 0);

            e1->dual = e2;
            e2->dual = e1;

            adj[i].push_back(e1);
            adj[j + JOB].push_back(e2);
        }
    }

    for(int i = 1; i <= n; i++) {
        Edge *e1 = new Edge(S, i, 1);
        Edge *e2 = new Edge(i, S, 0);

        Edge *e3 = new Edge(MEDIUM, i, 1);
        Edge *e4 = new Edge(i, MEDIUM, 0);

        e1->dual = e2;
        e2->dual = e1;
        e3->dual = e4;
        e4->dual = e3;

        adj[S].push_back(e1);
        adj[i].push_back(e2);
        adj[MEDIUM].push_back(e3);
        adj[i].push_back(e4);
    }

    for (int i = 1; i <= m; i++)
    {
        Edge *e1 = new Edge(E, i + JOB, 0);
        Edge *e2 = new Edge(i + JOB, E, 1);
        e1->dual = e2;
        e2->dual = e1;

        adj[E].push_back(e1);
        adj[i + JOB].push_back(e2);
    }

    Edge *e1 = new Edge(MEDIUM, S, 0);
    Edge *e2 = new Edge(S, MEDIUM, k);
    e1->dual = e2;
    e2->dual = e1;

    adj[S].push_back(e2);
    adj[MEDIUM].push_back(e1);

    cout << maxFlow() << endl;
}