#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n, m;

char _map[51][51];
int vst[51][51];

bool dfs(int sy, int sx, int y, int x, int num) {
    bool flag = false;
    for(int k = 0; k < 4; k++) {
        int nx = dx[k] + x;
        int ny = dy[k] + y;

        if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
        if(_map[ny][nx] != _map[sy][sx]) continue;

        // printf("ny: %d, nx: %d, sy: %d, sx: %d\n", ny, nx, sy, sx);
        if(ny == sy && nx == sx && num >= 4) {
            cout << "Yes" << endl;
            exit(0);
        }
        if(vst[ny][nx]) continue;
        vst[ny][nx] = 1;
        flag = dfs(sy, sx, ny, nx, num + 1);
        vst[ny][nx] = 0;
    }
    return flag;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // memset과 fill의 차이점은 무엇인가?
    memset(vst, 0, sizeof(vst));

    cin >> n >> m;
    for(int i =0; i < n; i++) {
        cin >> _map[i];
    }


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            vst[i][j] = 1;
            dfs(i, j, i, j, 1);
            vst[i][j] = 0;
        }
    }

    cout << "No" << endl;

    return 0;
}