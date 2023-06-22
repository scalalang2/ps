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

    set<string> s;
    int N, M;
    cin >> N >> M;
    while(N--) {
        string x;
        cin >> x;
        s.insert(x);
    }

    int ans = 0;
    while(M--) {
        string x;
        cin >> x;
        if(s.find(x) != s.end()) ans++;
    }

    cout << ans << endl;

    return 0;
}