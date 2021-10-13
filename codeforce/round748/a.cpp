#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    while(n--) {
        int a, b, c;
        cin >> a >> b >> c;
        int m = max(a, b);
        m = max(m, c);

        if(m == a && a != b && a != c) cout << 0 << ' ';
        else if(m == a && (m == b || m == c)) cout << 1 << ' ';
        else cout << m-a+1 << ' ';

        if (m == b && b != a && b != c)
            cout << 0 << ' ';
        else if (m == b && (m == a || m == c))
            cout << 1 << ' ';
        else
            cout << m - b + 1 << ' ';

        if (m == c && c != a && c != b)
            cout << 0 << ' ';
        else if (m == c && (m == a || m == b))
            cout << 1 << ' ';
        else
            cout << m - c + 1 << ' ';
        
        cout << endl;
    }
}