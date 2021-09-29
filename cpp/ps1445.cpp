#include <bits/stdc++.h>
using namespace std;
using ii = pair<pair<int,int>, pair<int, int> >;

const int nxm = 51;
int n, m;

char arr[nxm][nxm];
int d[nxm][nxm];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool chk(int x, int y) {
    int ret = false;
    for(int k = 0; k < 4; k++) {
        int nx = dx[k] + x;
        int ny = dy[k] + y;
        if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
        if(arr[ny][nx] == 'g') ret = true;
    }

    return ret;
}

void bfs(int x, int y, int fx, int fy) {
    // geater = 오름차순
    // less = 내림차순
    priority_queue<ii, vector<ii>, greater<ii> > queue;
    queue.push(make_pair(make_pair(0, 0), make_pair(x, y)));
    d[y][x] = 0;

    while(!queue.empty()) {
        pair<pair<int, int>, pair<int, int> > it = queue.top();
        queue.pop();

        int ng = it.first.first;
        int nadjg = it.first.second;
        int x = it.second.first;
        int y = it.second.second;
        bool flag = false;

        for(int k = 0; k < 4; k++) {
            int nx = dx[k] + x;
            int ny = dy[k] + y;
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(d[ny][nx] != -1) continue;

            if(nx == fx && ny == fy) {
                cout << ng << " " << nadjg << endl;
                flag = true;
                break;
            }

            if(arr[ny][nx] == 'g') {
                queue.push(make_pair(make_pair(ng + 1, nadjg), make_pair(nx, ny)));
            } else if(arr[ny][nx] == '.') {
                if(chk(nx, ny)) {
                    queue.push(make_pair(make_pair(ng, nadjg + 1), make_pair(nx,ny)));
                } else {
                    queue.push(make_pair(make_pair(ng, nadjg), make_pair(nx, ny)));
                }
            }
            
            d[ny][nx] = d[y][x] + 1;
        }

        if(flag) break;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int sx, sy, fx, fy;
    memset(d, -1, sizeof(d));

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 'S') {
                sx = j; sy = i;
            }
            if(arr[i][j] == 'F') {
                fx = j; fy = i;
            }
        }
    }

    bfs(sx, sy, fx, fy);

    return 0;
}