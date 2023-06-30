#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, c;
        cin >> n >> c;
        
        // 이거 기억해둘만 하다 무조건 올림 처리 하는 테크닉
        // (a + b - 1) / b
        cout << (n + c - 1) / c << '\n';
    }


    return 0;
}