#include<bits/stdc++.h>

using namespace std;

int h, w;
int dx[2] = {0, 1};
int dy[2] = {1, 0};
int ans = 0;
map<int, int> m;
vector<vector<int>> G(10, vector<int>(10));

void dfs(int x, int y) {
    if(x == w-1 && y == h-1) {
        ans++;
        return;
    }

    for(int i = 0; i < 2; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
        if(m[G[ny][nx]]) continue;
        m[G[ny][nx]]++;
        dfs(nx, ny);
        m[G[ny][nx]]--;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> h >> w;

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> G[i][j];
        }
    }

    m[G[0][0]]++;
    dfs(0, 0);

    cout << ans << endl;

    return 0;
}