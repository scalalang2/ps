#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    string x;
    cin >> x;

    int has_good = 0;
    int has_x = 0;
    for(int i = 0; i < n; i++) {
        if(x[i] == 'o') {
            has_good = 1;
        }
        if(x[i] == 'x') {
            has_x = 1;
        }
    }
    if(has_good && !has_x) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}