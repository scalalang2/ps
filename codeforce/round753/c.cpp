#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        int a[200001];
        fill(a, a + 200001, 0);

        for(int i = 0; i < n; i++)
            cin >> a[i];
        
        sort(a, a + n);
        int min = a[0];
        
    }
} 