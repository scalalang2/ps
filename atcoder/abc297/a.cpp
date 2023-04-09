#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    for(int i = 1; i < n; i++) {
        int diff = v[i] - v[i-1];
        if(diff <= k) {
            cout << v[i] << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}