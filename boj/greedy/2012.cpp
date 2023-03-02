#include<bits/stdc++.h>

using namespace std;

int n;
long long arr[500001] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n, less<int>());
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        ans += abs(arr[i] - (i + 1));
    }

    cout << ans << endl;

    return 0;
}