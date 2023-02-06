#include<bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string x;
    cin >> x;

    vector<int> v;
    int tmp = 0;
    for(int i = 0; i < x.size(); i++) {
        if(x[i] == '<') {
            if(i > 0 && tmp > 0) v.push_back(tmp);
            tmp = 0;
            v.push_back(0);
        } else {
            tmp++;
        }
    }
    if(tmp > 0) v.push_back(tmp);
    ll ans = 0;
    int c = 0;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] == 0) {
            c++;
            ans += c;
        } else {
            if(v[i] > c) {
                ans -= c;
                while(v[i]) {
                    ans += v[i];
                    v[i]--;
                }
            } else {
                while(--v[i]) ans += v[i];
            }
            
            c = 0;
        }
    }

    cout << ans << endl;

    return 0;
}
