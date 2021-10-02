#include<bits/stdc++.h>
using namespace std;

int n, s;
int a[51];

void sort_times() {
    for (int i = 0; i < n; i++){
        if(s == 0) break;

        int mx = -1;
        int idx = -1;
        for (int j = i, k = 0; j < n && k <= s; j++, k++)
            if (mx < a[j]) {
                mx = a[j];
                idx = j;
            }

        for (int j = idx; j > i && s; j--, s--) {
            int temp = a[j-1];
            a[j-1] = a[j];
            a[j] = temp;
        }
    }
}

int main () {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> s;
    sort_times();
    for(int i = 0; i < n; i++) {
        if(i == n-1) {
            cout << a[i] << '\n';
        } else {
            cout << a[i] << ' ';
        }
    }
}