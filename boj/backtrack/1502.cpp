#include<bits/stdc++.h>

using namespace std;

using pp = pair<int,int>;

int t;
int table[101][101];
int m,n;
int a,b,c,d;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
vector<pp> v;

bool inrange(int y, int x) {
    return y >= 0 && y < m && x >= 0 && x < n;
}

bool is_split() {
    int cnt = 0;
    queue<pp> q;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(table[i][j] == 1) visited[i][j] = true;
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(!visited[i][j]) {
                cnt++;
                visited[i][j] = true;
                q.push({i, j});
                while(!q.empty()) {
                    pp curr = q.front();
                    q.pop();
                    for(int k = 0; k < 4; k++) {
                        int ny = curr.first + dy[k];
                        int nx = curr.second + dx[k];
                        if(ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
                        if(visited[ny][nx]) continue;
                        visited[ny][nx] = true;
                        q.push({ny, nx});
                    }
                }
            }
        }
    }

    return cnt > 1;
}

bool dfs(pp curr, int cnt) {
    if(curr.first == a && curr.second == b) {
        if(cnt == m * n) return true;
        else return false;
    }

    vector<pp> next;
    for(int k = 0; k < 4; k++) {
        int ny = curr.first + dy[k];
        int nx = curr.second + dx[k];
        if(ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
        if(table[ny][nx] == 1) continue;
        table[ny][nx] = 1;
        if(is_split()) {
            table[ny][nx] = 0;
            continue;
        }
        v.push_back({ny, nx});
        if(dfs({ny, nx}, cnt + 1)) return true;
        table[ny][nx] = 0;
        v.pop_back();
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> t;
    while(t--) {
        cin >> m >> n;
        cin >> a >> b >> c >> d;
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                table[i][j] = 0;
            }
        }
        a--;
        b--;
        c--;
        d--;
        table[c][d] = 1;
        v = vector<pp>();
        v.push_back({c, d});

        if(dfs({c,d}, 1)) {
            cout << 1 << endl;
            for(auto p : v) {
                cout << p.first+1 << " " << p.second+1 << endl;
            }
        } else {
            cout << "-1" << endl;
        }
    }

    return 0;
}