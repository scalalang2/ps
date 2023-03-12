#include<bits/stdc++.h>

using namespace std;

const int maxn = 400005;
vector<vector<int>> G(maxn);
int N, M;
int X, Y;

bool visited[maxn];

bool has_cycle(int u, int p) {
    visited[u] = true;
    for(int v : G[u]) {
        if(v == p) continue;
        if(visited[v]) return true;
        if(has_cycle(v, u)) return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int u, v;
        char c, d;
        cin >> u >> c >> v >> d;

        if(c == 'R') {
            u *= 2;
        } else {
            u *= 2;
            u++;
        }

        if(d == 'R') {
            v *= 2;
        } else {
            v *= 2;
            v++;
        }

        G[u].push_back(v);
        G[v].push_back(u);
    }

    for(int i = 2; i <= 2*N; i+=2) {
        G[i].push_back(i+1);
        G[i+1].push_back(i);
    }

    for(int i = 2; i <= 2*N; i += 2) {
        if(!visited[i]) {
            if(has_cycle(i, -1)) {
                X++;
            } else {
                Y++;
            }
        }
    }
    cout << X << " " << Y << endl;

    
    return 0;
}