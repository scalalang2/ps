#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        int ans = 0;
        int arr[200001];
        memset(arr, 0, 200001);

        cin >> n;

        for(int i = 0; i < n; i++) {
            int v;
            cin >> v;
            if(v - i >= 0) {
                if(i > 0) ans += arr[v-i];
                arr[v-i]++;
            }
        }

        cout << ans << endl;
    }


    return 0;
}