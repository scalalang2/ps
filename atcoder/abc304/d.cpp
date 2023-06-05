#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

const int mxn = 200002;

ll p[mxn], q[mxn];
ll a[mxn], b[mxn];

map<pll, ll> mp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int w, h, n, A, B;
    cin >> w >> h;
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> p[i] >> q[i];
    cin >> A;
    for(int i = 1; i <= A; i++) cin >> a[i];
    cin >> B;
    for(int i = 1; i <= B; i++) cin >> b[i];
    a[A+1] = w;
    b[B+1] = h;

    for(int i = 1; i <= n; i++) {
        ll X = lower_bound(a+1, a+A+2, p[i]) - a;
        ll Y = lower_bound(b+1, b+B+2, q[i]) - b;

        mp[{X, Y}]++;
    }

    ll M = 0;
    ll m = llINF;

    for(auto it = mp.begin(); it != mp.end(); it++) {
        M = max(M, it->second);
        m = min(m, it->second);
    }

    if(mp.size() != (A+1)*(B+1)) {
        m = 0;
    }

    cout << m << " " << M;

    return 0;
}