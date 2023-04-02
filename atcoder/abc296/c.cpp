#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxn = 200005;
ll a[maxn];
ll n, x;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> a[i];
    
    sort(a, a + n);

    // lower_bound
    for(int i = 0; i < n; i++) {
        int base = a[i];
        int target = a[i] - x;

        ll li = lower_bound(a, a + n, target) - a;
        if(li < n && a[li] == target) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}