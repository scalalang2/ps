#include<bits/stdc++.h>

using namespace std;


int n;
int A[101][101];
int B[101][101];

vector<vector<int>> rotate(vector<vector<int>> ARR) {
    vector<vector<int>> ret(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ret[i][j] = ARR[n - j - 1][i];
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> B[i][j];
        }
    }

    vector<vector<int>> ARR(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ARR[i][j] = A[i][j];
        }
    }

    for (int i = 0; i < 4; i++)
    {
        ARR = rotate(ARR);

        bool ok = true;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (ARR[i][j] == 1 && ARR[i][j] != B[i][j]){
                    ok = false;
                }
            }
        }
        if (ok)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}