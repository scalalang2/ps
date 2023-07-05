#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int n, k;
string tmp;
vector<vector<int>> origin;

set<pi> normalize(set<pi> ret) {
    set<pi> new_response;
    if(ret.size() > 0) {
        int minx = INF, miny = INF;
        for(auto i : ret) {
            minx = min(minx, i.first);
            miny = min(miny, i.second);
        }

        for(auto &p : ret) {
            new_response.insert({p.first - minx, p.second - miny});
        }
    }

    return new_response;
}

set<pi> convert(vector<vector<int>> v) {
    set<pi> ret;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(v[i][j] == 1) {
                ret.insert({i, j});
            }
        }
    }
    return normalize(ret);
}

set<pi> merge(set<pi> a, set<pi> b) {
    set<pi> ret;
    for(auto i : a) {
        ret.insert(i);
    }
    for(auto i : b) {
        ret.insert(i);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    origin.resize(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        for(int j = 0; j < n; j++) {
            origin[i][j] = tmp[j] == '#' ? 1 : 0;
        }
    }

    vector<set<pi>> pieces;
    while(k--) {
        vector<vector<int>> piece(n, vector<int>(n));
        for(int i = 0; i < n; i++) {
            cin >> tmp;
            for(int j = 0; j < n; j++) {
                piece[i][j] = tmp[j] == '#' ? 1 : 0;
            }
        }
        pieces.push_back(convert(piece));
    }
    set<pi> originSet = convert(origin);

    k = pieces.size();
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
            if (i == j) continue;
            for(int ny = 0; ny < n; ny++) {
                for(int nx = 0; nx < n; nx++) {
                    set<pi> new_p;
                    for(auto p : pieces[j]) {
                        new_p.insert({(p.first + ny) % n, (p.second + nx)%n});
                    }

                    set<pi> merged = merge(pieces[i], new_p);
                    if(merged.size() != originSet.size()) continue;
                    bool flag = true;

                    auto o = originSet.begin();
                    auto m = merged.begin();
                    for(int l = 0; l < originSet.size(); l++) {
                        o++;
                        m++;
                        if(o->first != m->first || o->second != m->second) {
                            flag = false;
                            break;
                        }
                    }

                    if(flag) {
                        cout << min(i+1, j+1) << " " << max(i+1, j+1) << endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << "done" << endl;

    return 0;
}