#include<bits/stdc++.h>

using namespace std;

int n;
int arr[2001];
int ans = 0;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);
    for(int i = 0; i < n; i++) {
        int l = 0, r = n-1;
        while(l < r) {
            if(l == i) {
                l++; continue;
            } else if(r == i) {
                r--; continue;
            }
            if(arr[l] + arr[r] == arr[i]) {
                ans++;
                break;
            } else if(arr[l] + arr[r] < arr[i]) {
                l++;
            } else {
                r--;
            }
        }
    }

    cout << ans << endl;

    
    return 0;
}