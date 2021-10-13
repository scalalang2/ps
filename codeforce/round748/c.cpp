#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        priority_queue<int, vector<int> > Q;

        while(k--) {
            int tmp;
            cin >> tmp;
            Q.push(tmp);
        }
        
        int st = 0;
        int ans = 0;
        while(!Q.empty() && st < n) {
            int pos = Q.top();
            Q.pop();
            if(pos > st) {
                st += n - pos;
                ans++;
            } else {
                break;
            }
        }
        cout << ans << endl;
    }
}