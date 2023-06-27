#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int n, k, m, ans;
int sz = 1;
vector<pi> seg;

void update(int idx, int val) {
    idx += sz;
    seg[idx].first = val;
    seg[idx].second = 1;
    while(idx > 1) {
        idx /= 2;
        seg[idx].first = min(seg[idx*2].first, seg[idx*2+1].first);
        seg[idx].second = seg[idx*2].second + seg[idx*2+1].second;
    }
}

int query(int pos, int l, int r, int k) {
    if(l == r) {
        return l;
    }
    int mid = (l + r) / 2;
    if(seg[pos*2].second >= k) {
        return query(pos*2, l, mid, k);
    } else {
        return query(pos*2+1, mid+1, r, k-seg[pos*2].second);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    while(sz < k) sz <<= 1;
    seg.resize(sz * 2, {0,0});
    
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        m = i % k;

        update(m, x);
        if(i+1 >= k) {
            int v = query(1, 1, sz, (k+1)/2);
            cout << seg[sz + v].first << endl;
            ans += seg[sz + v].first;
        }
    }

    cout << ans << endl;

    return 0;
}