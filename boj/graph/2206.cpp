#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

string temp;
int table[1001][1001] = {0,};
int dist[1001][1001][2] = {0,};
int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // BFS 상태 공간에서 벽을 부수고 왔는데 안부수고 왔는지에 대한 상태도 추가해서 생각하기
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> temp;
        for(int j = 0; j < m; j++) {
            table[i][j] = temp[j] == '0' ? 0 : 1;
        }
    }

    int ans = 0;
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 1;

    while(!q.empty()) {
        int h, w, f;
        tie(h, w, f) = q.front();
        q.pop();

        if(h == n-1 && w == m-1) {
            cout << dist[h][w][f] << endl;
            return 0;
        }

        deque<pair<int, int>> dq;
        for(int k = 0; k < 4; k++) {
            int ny = h + dy[k];
            int nx = w + dx[k];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(table[ny][nx] == 1 && f == 0) {
                if(dist[ny][nx][1] != 0) continue;
                dist[ny][nx][1] = dist[h][w][0] + 1;
                q.push({ny, nx, 1});
            }
            if(table[ny][nx] == 0) {
                if(dist[ny][nx][f] != 0) continue;
                dist[ny][nx][f] = dist[h][w][f] + 1;
                q.push({ny, nx, f});
            }
        }
    }

    cout << -1 << endl;

    return 0;
}