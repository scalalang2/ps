#include <bits/stdc++.h>
using namespace std;

long long GRAVE = -20000;
long long INF = 1e18;
int w, h, g, e;
typedef pair<int,int> P;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
map<string, P> ghost;
long long _map[31][31];
long long _dist[31][31];

bool hasGhost(int x, int y) {
    return ghost.find(to_string(x) + "_" + to_string(y)) != ghost.end();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while(true){ 
        cin >> w >> h;
        if(w == 0 && h == 0) break;

        fill_n(&_map[0][0], sizeof(_map) / sizeof(**_map), 1);
        fill_n(&_dist[0][0], sizeof(_dist) / sizeof(**_dist), INF);
        ghost.clear();

        cin >> g;
        while(g--) {
            int x, y;
            cin >> x >> y;
            _map[y][x] = GRAVE;
        }

        cin >> e;
        while(e--) {
            int x1, y1, x2, y2, cost;
            cin >> x1 >> y1 >> x2 >> y2 >> cost;
            _map[y1][x1] = cost;
            ghost[to_string(x1) + "_" + to_string(y1)] = make_pair(x2, y2);
        }
        
        _dist[0][0] = 0;
        bool has_cycle = false;
        for(int k = 0; k < w * h; k++) {
            for(int i = 0; i < h; i++) {
                for(int j = 0; j < w; j++) {
                    for(int l = 0; l < 4; l++) {
                        int nx = dx[l] + j;
                        int ny = dy[l] + i;

                        if(nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
                        if(_dist[i][j] == INF) continue;
                        if(_map[ny][nx] == GRAVE) continue;

                        if(hasGhost(j, i)) {
                            int ex = ghost[to_string(j) + "_" + to_string(i)].first;
                            int ey = ghost[to_string(j) + "_" + to_string(i)].second;
                            if (_dist[i][j] + _map[i][j] < _dist[ey][ex]) {
                                _dist[ey][ex] = _dist[i][j] + _map[i][j];
                                if(k == w*h-1) has_cycle = true;
                            }
                        } else {
                            if(_dist[i][j] + 1 < _dist[ny][nx]) {
                                _dist[ny][nx] = _dist[i][j] + 1;
                                if (k == w*h-1)
                                    has_cycle = true;
                            }
                        }
                    }
                }
            }
        }

        if(has_cycle) {
            cout << "Never" << endl;
        } else if(_dist[h-1][w-1] == INF) {
            cout << "Impossible" << endl;
        } else {
            cout << _dist[h - 1][w - 1] << endl;
        }
    }
}