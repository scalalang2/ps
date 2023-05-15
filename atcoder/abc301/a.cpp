#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    string x;
    cin >> N >> x;

    int t = 0;
    int a = 0;
    for(int i = 0; i < N; i++) {
        if(x[i] == 'T') t++;
        else a++;
    }

    if(t == a) {
        if(x[N-1] == 'T') cout << "A";
        else cout << "T";
    } else if(t > a) {
        cout << "T";
    } else {
        cout << "A";
    }

    return 0;
}