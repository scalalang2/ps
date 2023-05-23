#include<bits/stdc++.h>

using namespace std;

char a[2] = {'p', 'i'};
char b[2] = {'k', 'a'};
char c[3] = {'c', 'h', 'u'};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string x;
    cin >> x;

    for(int i = 0; i < x.size();) {
        if(i+1 < x.size()) {
            if(x[i] == a[0] && x[i+1] == a[1]) {
                i += 2;
                continue;
            }
            if(x[i] == b[0] && x[i+1] == b[1]) {
                i += 2;
                continue;
            }
        }
        if(i+2 < x.size()) {
            if(x[i] == c[0] && x[i+1] == c[1] && x[i+2] == c[2]) {
                i += 3;
                continue;
            }
        }

        cout << "NO";
        return 0;
    }

    cout << "YES";

    return 0;
}