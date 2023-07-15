#include<bits/stdc++.h>

using namespace std;

int n1, n2, m;
vector<int> G[300001];
bool vis[300001] = {false};

int dist(int start) {
    queue<pair<int, int>> q;
    q.push({start, 0});
    vis[start] = true;

    int ret = 0;
    while(!q.empty()) {
        auto curr = q.front(); q.pop();
        ret = max(ret, curr.second);

        for(auto next : G[curr.first]) {
            if(!vis[next]) {
                vis[next] = true;
                q.push({next, curr.second + 1});
            }
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n1 >> n2 >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    // cout << dist(1) << " " << dist(n1+n2) << endl;

    cout << dist(1) + dist(n1+n2) + 1 << endl;
    return 0;
}