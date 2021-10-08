#include<bits/stdc++.h>

using namespace std;
stack<char> s;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int ans = 0;
    string text;
    cin >> text;

    for(int i = 0; i < text.size(); i++) {
        char c = text[i];
        if (c == '\n' or c == '\r')
            break;

        if (c == '('){
            s.push(c);
        }else{
            if (s.empty()){
                ans++;
            }else{
                s.pop();
            }
        }
    }

    ans += s.size();
    cout << ans << endl;
    
    return 0;
}