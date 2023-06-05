#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n; cin >> n;
    if(n < 1000) {
        cout << n;
        return 0;
    }

    int t = 0;
    while(n > 1000) {
        n /= 10;
        t++;
    }

    cout << n;
    while(t--) cout << 0;

    return 0;
}