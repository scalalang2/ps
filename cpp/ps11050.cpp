#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fact(ll n) {
    ll ret = 1;
    for(int i = n; i > 0; i--) {
        ret *= i;
    }
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);cin.tie(0);

    int n, k;
    cin >> n >> k;

    // (n!/(n-r)!r!)
    cout << fact(n)/(fact(n-k)*fact(k));
    
    return 0;
}