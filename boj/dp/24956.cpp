#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int n;
string s;
ll MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    cin >> s;

    ll w = 0, h = 0, e = 0, ans = 0;
    for(auto c : s) {
        if(c == 'W') w+=1;
        else if(c == 'H') h+=w;
        else if(c == 'E') {
            ans = (ans*2 + e)%MOD;
            e+=h;
        }
    }

    cout << ans << endl;

    return 0;
}