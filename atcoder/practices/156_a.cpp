#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll A[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    ll ans = std::numeric_limits<ll>::max();
    for(int i = 0; i < n; i++) cin >> A[i];

    for(int i = 0; i <= 100; i++) {
        ll tmp = 0;
        for(int j = 0; j < n; j++) {
            tmp += ll(pow(A[j] - i, 2));
        }
        ans = min(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}