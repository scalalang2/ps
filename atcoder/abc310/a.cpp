#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, p, q;
    cin >> n >> p >> q;
    
    int m = INF;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        m = min(m, x);
    }

    cout << min(p, q + m) << endl;

    return 0;
}