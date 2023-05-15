#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
string s;
ll n;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> s >> n;
 
    ll ans = 0;
    // 일단 1은 불가항력이니까 전부 더해버려
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '1') ans |= (1LL << (s.size() - i - 1));
        else ans |= (0 << (s.size() - i - 1));
    }
 
    if(ans > n) {
        cout << -1 << endl;
        return 0;
    }
 
    // 물음표 자리를 1로 바꿔도 되겠니? 라고 물어보기
    // 아니 진심 왜 틀리는 거지..?
    for(int i = s.size() - 1; i >= 0; i--) {
        if(s[s.size() - i - 1] == '?' && (ans | 1LL << i) <= n) {
            ans |= 1LL << i;
        }
    }
 
    cout << ans << endl;
 
    return 0;
}