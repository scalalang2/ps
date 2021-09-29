#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int a, b = 0;
    for(int i = 2; i <= n; i*=2) {
        a += n/i;
    }

    for (int i = 5; i <= n; i*=5)
    {
        b += n/i;
    }

    cout << min(a, b) << endl;

    return 0;
}