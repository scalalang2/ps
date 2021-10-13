#include <bits/stdc++.h>

using namespace std;

int n, k;

int chk[51];
int psum[51];

int get_k() {
    int ret = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if(chk[i] == 0) cnt++;
        else ret += cnt;
    }
    
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    fill(chk, chk + 51, 0);

    int cnt = 0;
    int kk = 0;
    bool flag = false;
    for(int i = n; i >= 1; i--) {
        if(get_k() == k) {
            flag = true;
            break;
        }
        chk[i] = 1;
        if(get_k() > k) {
            chk[i] = 0;
        }
    }

    if(!flag && get_k() != k) {
        cout << -1 << endl;
        exit(0);
    }

    for(int i = 1; i <= n; i++) {
        if(chk[i] == 0) cout << "A";
        else cout << "B";
    }

    cout << endl;
}
