#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        map<int, int> m;
        set<int> b;

        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            m[x] += 1;

            b.insert(x);
            b.insert(x + 1);
        }

        int l = 0;
        int ans = 0;
        // auto 구문은 for문에서만 쓰자
        for(auto x: b) {
            int c = m[x];
            ans += max(0, c - l);
            l = c;
        }

        cout << ans << endl;
    }

    return 0;
}