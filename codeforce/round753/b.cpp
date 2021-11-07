#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;
    while(t--) {
        ll x, n;
        cin >> x >> n;
        
        ll ne = n/2;
        ll no = n/2 + (n%2);
        ll se = ne*(ne+1);
        ll so = pow(no, 2);

        cout << x + so - se << endl;
    }
}