#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string x;
    cin >> x;

    for(int i = 0; i < x.size(); i++) {
        char c = x[i];
        if(c >= 'a' && c <= 'z') {
            c = c - 'a' + 'A';
        }

        cout << c;
    }
    return 0;
}