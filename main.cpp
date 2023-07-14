#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

set<int> wss;
set<int> ds;
map<int, int> wm;
map<int, int> dm;
vector<tuple<int, int, int>> v;

struct segtree {
    int sz;
    vector<int> tree;

    segtree(int size) {
        sz = 1;
        while(sz < size) sz <<= 1;
        tree.resize(sz * 2, INF);
    }

    int get(int idx) {
        return tree[idx + sz];
    }

    void update(int idx, int val) {
        idx += sz;
        tree[idx] = val;
        while(idx > 1) {
            idx /= 2;
            tree[idx] = min(tree[idx*2], tree[idx*2+1]);
        }
    }

    int query(int node, int l, int r, int s, int e) {
        if(r < s || e < l) return INF;
        if(s <= l && r <= e) return tree[node];
        int mid = (l + r) / 2;
        return min(query(node*2, l, mid, s, e), query(node*2+1, mid+1, r, s, e));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int h, w, d, h_, w_, d_;
        cin >> h >> w >> d;
        h_ = max(h, max(w, d));
        d_ = min(h, min(w, d));
        w_ = h + w + d - h_ - d_;

        wss.insert(w_);
        ds.insert(d_);
        v.push_back({h_, w_, d_});
    }

    // 좌표 압축 (1 ~ n) 사이로 압축하기
    int idx = 1;
    for(auto c : wss) {
        if(wm.find(c) == wm.end())
            wm[c] = idx++;
    }
    idx = 1;
    for(auto c : ds) {
        if(dm.find(c) == dm.end())
            dm[c] = idx++;
    }

    sort(v.begin(), v.end(), [](tuple<int, int, int> a, tuple<int, int, int> b) {
        if(get<0>(a) == get<0>(b)) {
            if(get<1>(a) == get<1>(b)) return get<2>(a) > get<2>(b);
            return get<1>(a) > get<1>(b);
        }
        return get<0>(a) < get<0>(b);
    });

    segtree st(n);
    for(int i = 0; i < n; i++) {
        int h_, w_, d_;
        int w = wm[get<1>(v[i])];
        int d = dm[get<2>(v[i])];

        if(st.query(1, 1, st.sz, 1, w-1) < d) {
            cout << "Yes" << endl;
            return 0;
        }

        // 얘는 인덱스가 0번부터 시작했었지 참참
        st.update(w-1, min(st.get(w-1), d));
    }
    cout << "No" << endl;

    return 0;
}