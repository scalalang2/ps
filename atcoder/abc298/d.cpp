#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll MOD = 998244353;
ll po[1000005];

/**
 * 
 * 
*/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    deque<ll> S(1,1);
    ll ans = 1;

    po[0]=1;
    int digit = 1;
    int q;
    cin >> q;

    for(int i = 1; i <= q; i++) {
        po[i] = po[i-1]*10;
        po[i] %= MOD;
    }
    while(q--) {
        int c;
        cin >> c;
        switch (c) {
            case 1: {
                ll a;
                cin >> a;
                S.push_back(a);
                ans *= 10;
                ans %= MOD;
                ans += a;
                ans %= MOD;
                digit++;
                break;
            }
            case 2: {
                ll b = S.front();
                ans = (ans+MOD-po[digit-1]*b%MOD)%MOD;
                digit--;
                S.pop_front();
                break;
            }
            case 3: {
                cout << ans << '\n';
                break;
            }
        }
    }

    return 0;
}