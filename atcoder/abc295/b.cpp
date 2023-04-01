#include<bits/stdc++.h>

using namespace std;

const int maxn = 20;
int r, c;
int table[maxn][maxn];

const int WALL = -1;
const int EMPTY = 0;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(int y, int x) {
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    queue<tuple<int, int, int>> q;
    q.push({y, x, 0});
    int dist = table[y][x];
    visited[y][x] = true;
    table[y][x] = EMPTY;

    while(!q.empty()) {
        int cy, cx, cd;
        tie(cy, cx, cd) = q.front();
        q.pop();

        for(int k = 0; k < 4; k++) {
            int nx = cx + dx[k];
            int ny = cy + dy[k];
            if(nx < 0 || nx >= c || ny < 0 || ny >= r) continue;
            if(visited[ny][nx]) continue;
            if(cd + 1 > dist) continue;
            if(table[ny][nx] != WALL && table[ny][nx] != EMPTY) {
                q.push({ny, nx, cd + 1});
                visited[ny][nx] = true;
            } else {
                table[ny][nx] = EMPTY;
                visited[ny][nx] = true;
                q.push({ny, nx, cd + 1});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < c; j++) {
            if(s[j] == '#') {
                table[i][j] = WALL;
            } else if(s[j] == '.') {
                table[i][j] = EMPTY;
            } else{
                table[i][j] = s[j] - '0';
            }
        }
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(table[i][j] > 0) {
                bfs(i, j);
            }
        }
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(table[i][j] == EMPTY) {
                cout << ".";
            } else {
                cout << "#";
            }
        }
        cout << endl;
    }
    return 0;
}