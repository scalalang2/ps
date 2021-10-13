#include <bits/stdc++.h>

using namespace std;

int n,v,e;
int kist, sear;
typedef pair<int, int> P;

vector<P> adj[1001];
int team[101];

P dijkstra(int node) {
    priority_queue<P, vector<P>, greater<P> > queue;
    int dist[1001];
    fill(dist, dist + 1001, INT_MAX);

    queue.push(make_pair(0, node));
    dist[node] = 0;
    while(!queue.empty()) {
        P curr = queue.top();
        queue.pop();

        for(int i = 0; i < adj[curr.second].size(); i++) {
            P nxt = adj[curr.second][i];
            if(curr.first + nxt.first < dist[nxt.second]){
                dist[nxt.second] = curr.first + nxt.first;
                queue.push(make_pair(dist[nxt.second], nxt.second));
            }
        }
    }
    
    int k_d = dist[kist];
    if(k_d == INT_MAX) k_d = -1;

    int s_d = dist[sear];
    if(s_d == INT_MAX) s_d = -1;

    return make_pair(k_d, s_d);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> v >> e;
    cin >> kist >> sear;
    for(int i = 0; i < n; i++) {
        cin >> team[i];
    }

    for(int i = 0; i < e; i++) {
        int f, s, c;
        cin >> f >> s >> c;
        adj[f].push_back(make_pair(c, s));
        adj[s].push_back(make_pair(c, f));
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        pair<int, int> p = dijkstra(team[i]);
        ans += p.first + p.second;
    }

    if(ans == n * -2) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}