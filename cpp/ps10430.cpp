// 백준 10430
#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int A, B, C;
    cin >> A >> B >> C;
    // (A + B) % C는 ((A % C) + (B % C)) % C 와 같을까
    // (A×B) % C는 ((A % C) × (B % C)) % C 와 같을까

    cout << (A+B)%C << endl;
    cout << ((A % C) + (B % C)) % C << endl;
    cout << (A*B)%C << endl;
    cout << ((A % C) * (B % C)) % C << endl;
}