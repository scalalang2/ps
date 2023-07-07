#include<bits/stdc++.h>

#define endl '\n';

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int n, m;
int dist[101][101];
int route[101][101];

vector<int> findpath(int start, int end) {
    vector<int> ret;
    int k = route[start][end];
    while(k != 0) {
        ret.push_back(k);
        k = route[start][k];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for(int i = 1; i <= 100; i++) {
        for(int j = 1; j <= 100; j++) {
            if(i != j) dist[i][j] = INF;
            route[i][j] = 0;
        }
    }

    cin >> n;
    cin >> m;
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        route[a][b] = a;
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) { 
            for(int j = 1; j <= n; j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    route[i][j] = route[k][j];
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(dist[i][j] == INF) cout << 0 << " ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(dist[i][j] == 0) {
                cout << 0 << endl;
                continue;
            }

            auto a = findpath(i, j);
            if(a.size() == 0 || dist[i][j] == INF) {
                cout << 0 << endl;
                continue;
            }
            cout << a.size() + 1 << " ";
            for(int l = a.size()-1; l >= 0; l--) {
                cout << a[l] << " ";
            }
            cout << j << endl;
        }
    }

    return 0;
}