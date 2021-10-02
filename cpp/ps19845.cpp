#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, q;

ll a[250001];
ll f[250001];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    for(int i = n-1; i >= 0; i--) {
        ll temp;
        cin >> temp;
        f[n-i-1] = temp;
        a[i] = temp;
    }

    while(q--) {
        ll x, y;
        cin >> x >> y;
        if(f[y-1] < x) {
            cout << 0 << endl;
        } else {
            ll xcnt = lower_bound(a, a + n, x) - a;
            cout << f[y - 1] - x + 1 + (n - xcnt - y) << endl;
        }
    }

    return 0;
}
