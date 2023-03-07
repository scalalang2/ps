#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int ans = 0;
    int cow[11];
    memset(cow, -1, sizeof(cow));

    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if(cow[a] != -1 && cow[a] != b) ans++;
        cow[a] = b;
    }

    cout << ans;
    return 0;
}