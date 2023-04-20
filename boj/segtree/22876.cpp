#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using pp = pair<int, ll>;

const int mxn = 1000010;
int n;
ll ans;

// X축을 베었을 때 나올 수 있는 Y좌표의 개수
vector<pp> ys[mxn];

// Y축을 베었을 때 나올 수 있는 X좌표의 개수
vector<pp> xs[mxn];

vector<tuple<int, int, ll>> points;

struct segtree {
    int size;
    vector<pair<ll, ll>> tree;
    vector<ll> values;

    pair<ll, ll> merge(pair<ll, ll> a, pair<ll, ll> b) {
        if(a.first < b.first) swap(a, b);
        return {a.first, max(a.second, b.first)};
    }

    segtree(int n) {
        int sz = 1;
        while(sz < n) sz <<= 1;
        size = sz * 2;
        tree.resize(size);
    }

    // update의 경우에는 인덱스 시작이 0번이고
    void update(int idx, ll v) {
        idx += size/2;
        tree[idx] = {v, 0};
        while(idx > 1) {
            idx /= 2;
            tree[idx] = merge(tree[idx*2], tree[idx*2+1]);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ans = 0;
    vector<ll> tmpx(mxn);
    vector<ll> tmpy(mxn);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;
        ll v;
        cin >> x >> y >> v;
        points.push_back(make_tuple(x, y, v));
        tmpx[x] += v;
        tmpy[y] += v;
    }
    for(int i = 0; i < n; i++) {
        int x, y, v;
        tie(x, y, v) = points[i];
        ys[x].push_back({y, v});
        xs[y].push_back({x, v});
    }
    segtree segx = segtree(mxn);
    segtree segy = segtree(mxn);
    for(int i = 0; i < mxn; i++) {
        if(tmpx[i] > 0) segx.update(i, tmpx[i]);
        if(tmpy[i] > 0) segy.update(i, tmpy[i]);
    }
    
    // X를 먼저 고정시키고 생각해보자
    for(int x = 0; x < mxn; x++) {
        if(tmpx[x] == 0) continue;
        for(auto ysv : ys[x]) {
            segy.update(ysv.first, tmpy[ysv.first] - ysv.second);
        }

        pair<ll, ll> ret = segy.tree[1];
        ans = max(ans, tmpx[x] + ret.first + ret.second);

        // 원상복구
        for(auto ysv : ys[x]) {
            segy.update(ysv.first, tmpy[ysv.first]);
        }
    }

    for(int y = 0; y < mxn; y++) {
        if(tmpy[y] == 0) continue;
        for(auto ysv : xs[y]) {
            segx.update(ysv.first, tmpx[ysv.first] - ysv.second);
        }

        pair<ll, ll> ret = segx.tree[1];
        ans = max(ans, tmpy[y] + ret.first + ret.second);

        // 원상복구
        for(auto ysv : xs[y]) {
            segx.update(ysv.first, tmpx[ysv.first]);
        }
    }

    sort(tmpx.begin(), tmpx.end(), greater<ll>());
    sort(tmpy.begin(), tmpy.end(), greater<ll>());

    // X축을 3번 베고 Y축을 세번 베었을 때의 최댓값을 구함
    ans = max(ans, tmpx[0] + tmpx[1] + tmpx[2]);
    ans = max(ans, tmpy[0] + tmpy[1] + tmpy[2]);
    cout << ans << endl;
    
    return 0;
}