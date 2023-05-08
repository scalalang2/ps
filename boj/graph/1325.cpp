#include<bits/stdc++.h>

using namespace std;

int n,m;
vector<vector<int>> G;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    G.resize(n+1);
    while(m--) {
        int u,v;
        cin >> u >> v;
        G[v].push_back(u);
    }

    vector<pair<int, int>> ans;
    for(int i = 1; i <= n; i++) {
        vector<bool> visited(n+1, false);
        int cnt = 0;
        visited[i] = true;
        queue<int> q;
        q.push(i);
        while(!q.empty()) {
            int cur = q.front();q.pop();
            cnt += 1;
            for(auto nxt : G[cur]) {
                if(visited[nxt]) continue;
                visited[nxt] = true;
                q.push(nxt);
            }
        }

        ans.push_back({i, cnt});
    }

    sort(ans.begin(), ans.end(), [](pair<int, int> a, pair<int, int> b) {
        if(a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    });

    int max = INT_MAX;
    for(int i = 0; i < ans.size(); i++) {
        if(max == INT_MAX) {
            max = ans[i].second;
        }

        if(max == ans[i].second) {
            cout << ans[i].first << " ";
        } else {
            break;
        }
    }

    return 0;
}