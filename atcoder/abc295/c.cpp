#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int ans = 0;
    for(int i = 1; i < n;) {
        if(a[i] == a[i - 1]) {
            ans++;
            i += 2;
        } else {
            i++;
        }
    }

    cout << ans << endl;

    return 0;
}