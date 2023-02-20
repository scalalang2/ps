#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using PP = pair<ll, ll>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string t;
    cin >> t;

    ll ans = 0;
    stack<PP> index_st;
    
    for(int i = 0; i < t.length(); i++) {
        if(t[i] == '(') {
            if(i > 0) index_st.push(PP(ll(t[i-1] - '0'), ans-1));
            ans = 0;
        } else if(t[i] == ')') {
            PP pp = index_st.top();
            index_st.pop();
            ans = (pp.first * ans) + pp.second;
        } else {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}