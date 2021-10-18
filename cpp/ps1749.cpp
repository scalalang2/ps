#include <bits/stdc++.h>
using namespace std;

const int MAX = 201;

int arr[MAX][MAX];
int psum[MAX][MAX];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> arr[i][j];

    psum[1][1] = arr[1][1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) 
            psum[i][j] = arr[i][j] + psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
    
    int ans = -1e19;

    for(int i = 1; i <= n; i++) {
        for(int j = 1;j <= m; j++) {
            for(int y = i; y <= n; y++) {
                for(int x = j; x <= m; x++) {
                    ans = max(ans, psum[y][x] - psum[y][j-1] - psum[i-1][x] + psum[i-1][j-1]);
                }
            }
        }
    }

    cout << ans << endl;
}