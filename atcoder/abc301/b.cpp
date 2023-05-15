#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i = 1; i < n; i++) {
        if(arr[i-1] < arr[i])
            for(int k = arr[i-1]; k < arr[i]; k++) {
                cout << k << " ";
            }
        
        if(arr[i-1] > arr[i])
            for(int k = arr[i-1]; k > arr[i]; k--) {
                cout << k << " ";
            }
    }
    cout << arr[n-1];

    return 0;
}