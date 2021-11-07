#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n, m;
    cin >> n >> m;

    if(n == 1) {
        cout << m/2 << endl;
        return 0;
    } else if(m == 1) {
        cout << n/2 << endl;
        return 0;
    }

    if(n%2 == 1 && m % 2 == 1) {
        cout << ((n-1) * (m-1))/2 + n/2 + m/2 << endl;
    } else if(n%2 == 0 && m % 2 == 1) {
        cout << (n * (m-1))/2 + n/2 << endl;
    } else if(n%2 == 1 && m % 2 == 0) {
        cout << ((n-1) * m) / 2 + m / 2 << endl;
    } else {
        cout << (n * m) / 2 << endl;
    }

    return 0;
}