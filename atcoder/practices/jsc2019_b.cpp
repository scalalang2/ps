#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, K;
ll arr[2001];
ll lesse[2001];
ll shrt[2001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> arr[i];

    for(int i = 0; i < N; i++) {
        // 현재값
        ll k = arr[i];
        for(int j = 0; j < N; j++) {
            if(j > i && k > arr[j]) shrt[i]++;
            if(i != j && k > arr[j]) lesse[i]++;
        }
    }

    ll ans = 0;
    ll mod = 1000000009;
    for(int i = 0; i < N; i++) {
        ll k = K-1;
        ans += (shrt[i] * K % mod) + (lesse[i] * (k * (k + 1)/2) % mod);
    }

    cout << ans % mod << endl;

    return 0;
}