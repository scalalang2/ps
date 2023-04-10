#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> v(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        string x;
        cin >> x;
        for(int j = 0; j < m; j++) {
            if(x[j] == 'T') v[i][j] = 1;
            else v[i][j] = 0;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(v[i][j] == 1 && v[i][j-1] == 1) {
                v[i][j] = 3;
                v[i][j-1] = 2;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == 0) cout << '.';
            else if(v[i][j] == 1) cout << 'T';
            else if(v[i][j] == 2) cout << 'P';
            else if(v[i][j] == 3) cout << 'C';
        }
        cout << endl;
    }

    return 0;
}