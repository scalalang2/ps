#include<bits/stdc++.h>
using namespace std;

int apple[100];
int students[100];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> students[i] >> apple[i];
    }

    int ret = 0;
    for(int i = 0; i < n; i++) {
        // cout << apple[i] / students[i] << endl;
        int num = apple[i] / students[i];
        ret += apple[i] - num * students[i];
    }

    cout << ret << endl;

    return 0;
}