#include <bits/stdc++.h>

using namespace std;

int arr[10001];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    if(n==1) {
        cout << -1 << endl;
        return 0;
    }

    int pos = n-1;
    for(int i = n-1; i > 0; i--) {
        if(arr[i] < arr[i+1]) pos--;
        else break;
    }
    if(pos == 0) {
        cout << -1 << endl;
        return 0;
    }
    int minI = 0;
    int minV = -1;
    for(int i = n; i > pos; i--) {
        if(minV < arr[i] && arr[i] < arr[pos]) {
            minV = arr[i];
            minI = i;
        }
    }
    swap(arr[pos], arr[minI]);
    for(int i = pos+1; i <= n; i++) {
        for(int j = i+1; j <= n; j++){
            if(arr[i] < arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
    for(int i = 1; i<=n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}