#include <bits/stdc++.h>
using namespace std;

int L, W, H, n, cube[21];
bool f = 1;

int func(int l, int w, int h) {
    if (!l || !w || !h)
        return 0;
    int k = l;
    if (w < k)
        k = w;
    if (h < k)
        k = h;

    int t = log2(k);
    do
    {
        if (!cube[t])
            continue;
        cube[t]--;
        int T = pow(2, t);
        return func(l - T, T, h) + func(l, w - T, h) + func(T, T, h - T) + 1;
    } while (--t >= 0);
    f = 0;
    
    return -1;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> L >> W >> H;
    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cube[a] = b;
    }

    int ans = func(L, W, H);
    if (f)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}