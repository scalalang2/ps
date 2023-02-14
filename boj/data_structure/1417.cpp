#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, a;
    cin >> n;
    cin >> a;

    priority_queue<int> Q;
    for(int i = 0; i < n-1;i++) {
        int x;
        cin >> x;
        Q.push(x);
    }

    int ans = 0;
    while(!Q.empty()) {
        int node = Q.top();
        if(a > node) {
            break;
        }

        a++; ans++;
        Q.pop();
        Q.push(--node);
    }

    cout << ans << endl;


    return 0;
}