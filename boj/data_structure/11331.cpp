#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while(1) {
        int n;
        cin >> n;
        if(n == 0) break;

        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];

        sort(v.begin(), v.end(), greater<int>());
        for(int i = 0; i < n; i++) {
            cout << v[i] << endl;
        }
    }

    return 0;
}