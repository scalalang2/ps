// 백준 1085
#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int ans = x;
    ans = min(ans, y);
    ans = min(ans, w-x);
    ans = min(ans, h-y);

    cout << ans << endl;
    return 0;
}