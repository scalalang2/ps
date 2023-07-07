#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

// 약수를 배수의 개수를 구하는 문제로 치환해서 푸는 문제
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;

    ll ans = 0;
    for(ll i = 1; i <= n; i++) {
        ans += n/i * i;
    }

    cout << ans << endl;
    return 0;
}