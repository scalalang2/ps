#include<bits/stdc++.h>

using namespace std;

int t;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    cin.get();
    while(t--) {
        getline(cin, s);
        if(s.length() == 0) {
            cout << 1 << endl;
            continue;
        }

        stack<int> st;
        int d = 0;
        int max_d = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '[') { st.push(++d); max_d = max(max_d, d); }
            else { st.pop(); d--; }
        }
        cout << int(pow(double(2), double(max_d))) << endl;
    }

    return 0;
}