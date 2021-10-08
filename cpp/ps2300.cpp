#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> xy;

int n;
int dp[10001];
xy a[10001];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // fill(dp, dp + 10001, INT_MAX);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i+1] = make_pair(x, y);
    }

    sort(a+1, a+n+1);
    for(int i = 1; i <= n; i++) {
        int lx = a[i].first;
        int rx = a[i].first;
        int y = abs(a[i].second);

        dp[i] = INT_MAX;
        for(int j = i - 1; j >= 0; j--) {
            int width = max(abs(rx - lx), 2 * y);
            dp[i] = min(dp[i], dp[j] + width);
            lx = a[j].first;
            y = max(y, abs(a[j].second));
        }
    }

    cout << dp[n] << endl;

    return 0;
}