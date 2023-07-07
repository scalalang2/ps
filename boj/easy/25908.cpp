#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;
const int mxn = 1e7 + 1;

int arr[mxn];

ll cnt(int x) {
    ll ret = 0;
    for(int i = 1; i <= x; i++) {
        // 1부터 x까지의 각 숫자가 
        // [1,x] 범위에 몇 개의 배수가 있는지 세는 것
        // x/i (e.g. 7/2 라고 하면 [1,7] 구간에는 2,4,6 이 세 개의 배수가 존재한다.)
        ret += x / i * ((i & 1) ? -1 : 1);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(arr, -1, sizeof(arr));

    int s, t;
    cin >> s >> t;
    cout << cnt(t) - cnt(s-1) << endl;

    return 0;
}