#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> P;

const int MAX = 21;
vector<P> adj[MAX];
int dist[MAX];
int pre[MAX];
int t, n, m;

void dijk(int st)
{
    priority_queue<P> queue;
    queue.push({0, st});
    dist[st] = 0;

    while (!queue.empty())
    {
        P p = queue.top();
        queue.pop();

        int cost = -p.first;
        int curr = p.second;
        if (cost > dist[curr])
            continue;

        for (const auto &el : adj[curr])
        {
            int c = el.first;
            int nxt = el.second;

            if (c + cost < dist[nxt])
            {
                dist[nxt] = c + cost;
                pre[nxt] = curr;
                queue.push({-dist[nxt], nxt});
            }
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

    cin >> t;
    int num = 1;
    while (t--)
    {
        cin >> n >> m;

        // 초기화
        fill(pre, pre + MAX, -1);
        fill(dist, dist + MAX, INT_MAX);
        for (int i = 0; i < MAX; i++)
            adj[i].clear();

        for (int i = 0; i < n; i++)
        {
            int u, v, c;
            cin >> u >> v >> c;
            adj[u].push_back(make_pair(c, v));
            adj[v].push_back(make_pair(c, u));
        }

        dijk(0);

        cout << "Case #" << num << ":";

        stack<int> ans;
        for (int k = m - 1; k > 0;)
        {
            ans.push(k = pre[k]);
        }

        if (ans.top())
        {
            cout << " -1\n";
        }
        else
        {
            while (!ans.empty())
            {
                cout << " " << ans.top();
                ans.pop();
            }
            cout << " " << m - 1 << "\n";
        }

        num++;
    }

    return 0;
}