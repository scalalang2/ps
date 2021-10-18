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
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
    }

    if(n == 1){
        cout << -1 << endl;
    } else {
        int pos = n-1;
        for(int i = n-1; i > 0; i--) {
            if(arr[i] > arr[i+1]) {
                pos--;
            } else {
                break;
            }
        }
        if(pos == 0) {
            cout << -1 << endl;
            return 0;
        }
        int j = n-1;
        for(int i = n; i > 0; i--) {
            if(arr[pos] < arr[i]) {
                j = i;
                break;
            }
        }
        
        swap(arr[pos], arr[j]);
        sort(arr + pos + 1, arr + n+1);

        for(int i = 1; i <= n;i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}