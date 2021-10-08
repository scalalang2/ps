#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> coord;

ll n;
ll total = 0;
ll A[100000];

vector<coord> arr;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;

        arr.push_back(make_pair(x, i));
        A[i] = x;
    }

    sort(arr.begin(), arr.end());
    return 0;
}