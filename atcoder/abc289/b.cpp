#include<bits/stdc++.h>

using namespace std;

int N, M;
int c[101];
int visited[101] = {0};

void dfs(int x) {
    visited[x] = 1;
    if(c[x] == -1) {
        cout << x << " ";
        return;
    }

    dfs(c[x]);
    cout << x << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    memset(c, -1, sizeof(c));

    for(int i = 0; i < M; i++) {
        int x;
        cin >> x;
        c[x] = x+1;
    }

    for(int i = 1; i <= N; i++) {
        if(visited[i] == 0) dfs(i);
    }

    return 0;
}