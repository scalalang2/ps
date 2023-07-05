#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int n;
vector<ll> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    ll total = 0;
    for(auto i : arr) total += i;
    total /= n;

    ll c1 = 0, c2 = 0;

    for(auto i : arr) {
        if(i > total + 1) c1 += (i - total - 1);
        else if(i < total) c2 += (total - i);
    }

    cout << max(c1, c2);

    return 0;
}