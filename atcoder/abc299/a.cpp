#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    string x;
    cin >> n;
    cin >> x;

    int low = -1;
    int high = 101;
    int xx = -1;

    for(int i = 0; i < n; i++) {
        if(x[i] == '|' && low == -1)  {
            low = i;
        } else if(x[i] == '|') {
            high = i;
        }

        if(x[i] == '*') {
            xx = i;
        }
    }

    if(low < xx && xx < high) {
        cout << "in";
    } else {
        cout << "out";
    }

    return 0;
}