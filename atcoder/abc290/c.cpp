#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int n, k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    vector<ll> v;
    v.resize(n);

    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    
    ll cnt = 0;
    ll ans = 0;
    ll before = 0;
    for(int i = 0; i < n; i++) {
        if(i == 0 && v[i] != 0) break;
        if(i == 0 && v[i] == 0) {
            ans++;
            cnt++;
            before = v[i];
            continue;
        }

        if(v[i] == before + 1 && cnt < k) {
            ans++;
            cnt++;
            before = v[i];
        }
    }

    cout << ans << endl;

    return 0;
}