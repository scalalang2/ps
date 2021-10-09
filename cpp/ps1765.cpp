#include <bits/stdc++.h>
using namespace std;

int f, n;

vector<int> F[1001];
vector<int> E[1001];
bool chk[1001];
int p[1001];

void mkf(int node) {
    chk[node] = true;
    for(int i = 0; i < F[node].size(); i++) {
        // 이미 방문한 경우는 지나친다.
        if(chk[F[node][i]]) continue;
        chk[F[node][i]] = true;
        mkf(F[node][i]);
    }

    for(int i = 0; i < E[node].size(); i++) {
        for(int j = 0; j < E[E[node][i]].size(); j++) {
            if (chk[E[E[node][i]][j]]) continue;
            chk[E[E[node][i]][j]] = true;
            mkf(E[E[node][i]][j]);
        }
    }
}

int main () {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> f;
    for(int i = 1; i <= f; i++)
        p[i] = i;

    cin >> n;
    while(n--) {
        char type;
        int a, b;
        cin >> type >> a >> b;
        if(type == 'E') {
            E[a].push_back(b);
            E[b].push_back(a);
        } else {
            F[a].push_back(b);
            F[b].push_back(a);
        }
    }

    int ans = 0;
    for(int i = 1; i <= f; i++) {
        if(!chk[i]) {
            mkf(i);
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}