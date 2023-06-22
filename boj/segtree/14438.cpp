#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int n, q;
int sz = 1;
vector<ll> seg;

// update의 인덱스는 1부터 시작일까 0부터 시작일까
// 이건 0부터 시작하는게 맞다.
void update(int idx, ll value) {
    idx += sz;
    seg[idx] = value;
    while(idx > 1) {
        idx /= 2;
        seg[idx] = min(seg[idx * 2], seg[idx * 2 + 1]);
    }
}

// L, R이 찾고자 하는 구간
// hi, lo가 전체 구간을 의미함
ll query(int pos, int L, int R, int hi, int lo) {
    if(R < lo || hi < L) return llINF;

    // 구간에 완전히 포함되어 있다. 어떤게?
    // 이건 hi, lo가 포함하는 걸 말하는게 아니라
    // L, R이 주어진 hi, lo를 포함하냐를 보는거지
    if(L <= lo && hi <= R) return seg[pos];
    int mid = (lo + hi) / 2;
    return min(query(pos * 2, L, R, mid, lo), query(pos * 2 + 1, L, R, hi, mid+1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    while(sz < n) {
        sz <<= 1;
    }
    seg.resize(sz * 2, llINF);
    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        update(i, x);
    }

    cin >> q;
    while(q--) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1) {
            update(b-1, c);
        } else {
            int ans = query(1, b, c, sz, 1);

            // endl좀 제발 그만써 !!!!!!!!
            cout << ans << '\n';
        }
    }

    return 0;
}