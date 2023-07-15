#include<bits/stdc++.h>

using namespace std;

int table[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
int dx[4] = {0, 0, 0, 0};
int dy[4] = {1, 0 , -1, 0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a, b;
    cin >> a >> b;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(table[i][j] == a) {
                for(int k = 0; k < 4; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x >= 0 && x < 3 && y >= 0 && y < 3 && table[x][y] == b) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
                break;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}