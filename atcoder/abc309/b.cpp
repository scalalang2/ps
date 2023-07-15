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

    vector<vector<int>> s(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        cin >> x;
        for(int j = 0; j < n; j++) {
            s[i][j] = x[j] - '0';
        }
    }

    // 새로운 테이블 복사 한 번 하고
    vector<vector<int>> t(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            t[i][j] = s[i][j];
        }
    }

    for(int i = 1; i < n; i++) {
        t[0][i] = s[0][i-1];
        t[i-1][0] = s[i][0];
        t[n-1][i-1] = s[n-1][i];
        t[i][n-1] = s[i-1][n-1];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << t[i][j];
        }
        cout << endl;
    }

    return 0;
}