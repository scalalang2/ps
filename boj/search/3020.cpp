#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int n, h;
vector<int> low;
vector<int> high;

int ans = INF;
map<int, int> cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> h;
    int x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        if(i%2 == 0) low.push_back(x);
        else high.push_back(x);
    }

    sort(low.begin(), low.end());
    sort(high.begin(), high.end());

    for(int i = 1; i <= h; i++) {
        int lower = low.end() - lower_bound(low.begin(), low.end(), i);
        int upper = high.end() - lower_bound(high.begin(), high.end(), h - i + 1);
        cnt[lower + upper]++;
        if(ans > lower + upper) ans = lower + upper;
    }

    cout << ans << " " << cnt[ans];

    return 0;
}