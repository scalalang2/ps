#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int a,b;
        cin >> a >> b;
        cout << lcm(a, b) << endl;
    }
    return 0;
}