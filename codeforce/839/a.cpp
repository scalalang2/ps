#include<bits/stdc++.h>
#include<string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        string e;
        cin >> e;
        cout << int(e[0] - '0') + int(e[2] - '0') << endl;
    }

    return 0;
}            