#include <bits/stdc++.h>
using namespace std;

int arr[100];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 7;
    int ans = 0;
    int mv = INT_MAX;
    int found = 0;

    while(t--) {
        int num;
        cin >> num;

        if(num % 2 == 1) {
            found = 1;
            mv = min(mv, num);
            ans += num;
        }
    }

    if(found) {
        cout << ans << endl;
        cout << mv << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}