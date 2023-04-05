#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    for(int i = 1; i < n; i++) {
        int g = gcd(v[0], v[i]);
        cout << v[0] / g << "/" << v[i] / g << "\n";
    }

    return 0;
}