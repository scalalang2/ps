#include<bits/stdc++.h>

using namespace std;

string t;
bool vst[27];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;

    int ans = 0;
    for(int i = 0; i < 52; i++) {
        if(vst[t[i]-'A']) continue;
        vector<int> v(27);
        fill(v.begin(), v.end(), -1);
        for(int j = i+1; j < 52; j++) {
            if(t[j] == t[i]) break;
            if(vst[t[j] - 'A']) continue;
            v[t[j]-'A'] *= -1;
        }
        for(auto x : v) {
            if(x == 1) ans++;
        }
        vst[t[i]-'A'] = true;
    }
    
    cout << ans << endl;

    return 0;
}