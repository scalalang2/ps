#include <bits/stdc++.h>

const int MAX = 100001;

using namespace std;

vector<int> adj[MAX];
char nodes[MAX];
int chk[MAX];
int ss[MAX];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fill(chk, chk + MAX, -1);
    int n;
    cin >> n;

    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    string s;
    cin >> s;
    for(int i = 0; i < n; i++)
        nodes[i+1] = s[i];

    int g = 0;
    for(int i = 1; i <= n; i++) {
        if(nodes[i] == 'B') continue;
        if(chk[i] != -1) continue;
        queue<int> Q;
        Q.push(i);
        chk[i] = g;
        int a = 1;
        while(!Q.empty()) {
            int curr = Q.front();
            Q.pop();

            for(int j = 0; j < adj[curr].size(); j++) {
                int nxt = adj[curr][j];
                if(nodes[nxt] == 'B') continue;
                if(chk[nxt] != -1) continue;
                chk[nxt] = g;
                a++;
                Q.push(nxt);
            }
        }
        ss[g] = a;
        g++;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(nodes[i] == 'R') continue;
        for (int j = 0; j < adj[i].size(); j++) {
            int nxt = adj[i][j];
            if(nodes[nxt] == 'B') continue;
            ans += ss[chk[nxt]];
        }
    }
    cout << ans << endl;
    return 0;
}