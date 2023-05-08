#include<bits/stdc++.h>

using namespace std;

int n, m, x, ans;
vector<int> G[100001];
bool visited[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    while(m--) {
        int u,v;
        cin >> u >> v;
        G[v].push_back(u);
    }
    cin >> x;
    ans = 0;

    queue<int> q;
    q.push(x);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(auto nxt : G[curr]) {
            if(visited[nxt]) continue;
            visited[nxt] = true;
            ans++;
            q.push(nxt);
        }
    }

    cout << ans << endl;

    return 0;
}