#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int table[5][5] = {0};
bool visited[5][5] = {false,};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
ll ans = 9223372036854775807;

void dfs(int r, int c, int apple, ll cnt) {
    if(apple == 3) {
        ans = min(ans, cnt);
        return;
    }

    for(int i = 0; i < 4; i++) {
        int nx = c + dx[i];
        int ny = r + dy[i];

        if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
        if(table[ny][nx] == -1 || visited[ny][nx]) continue;

        // cout << table[ny][nx] << " y:" << ny << " x:" << nx << endl;

        visited[ny][nx] = true;
        if(table[ny][nx] == 1) dfs(ny, nx, apple + 1, cnt + 1);
        else dfs(ny, nx, apple, cnt + 1);
        visited[ny][nx] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> table[i][j];
        }
    }

    int r, c;
    cin >> r >> c;

    visited[r][c] = true;
    dfs(r, c, 0, 0);
    if(ans == 9223372036854775807) cout << -1;
    else cout << ans;

    return 0;
}