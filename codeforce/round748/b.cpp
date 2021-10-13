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
        int num[18];
        fill(num, num + 18, 0);
        long long n;
        cin >> n;
        
        int i = 17;
        while(n != 0) {
            num[i] = n%10;
            i--;
            n /= 10;
        }

        int a = -3;
        for(int i = 17; i >= 0; i--) {
            if(num[i] == 0 && a == -3) {
                a = -2;
            } else if(num[i] == 0 && a == -2) {
                a = -1;
            } else if(a == -1) {
                a = i;
                break;
            }
        }

        int b = -2;
        for(int i = 17; i >= 0; i--) {
            if(num[i] == 0 && b == -2) {
                b = -1;
            } else if(num[i] == 5 && b == -1) {
                b = i;
                break;
            }
        }

        int c = -2;
        for (int i = 17; i >= 0; i--)
        {
            if (num[i] == 5 && c == -2)
            {
                c = -1;
            }
            else if (num[i] == 2 && c == -1)
            {
                c = i;
                break;
            }
        }

        int d = -2;
        for (int i = 17; i >= 0; i--)
        {
            if (num[i] == 5 && d == -2)
            {
                d = -1;
            }
            else if (num[i] == 7 && d == -1)
            {
                d = i;
                break;
            }
        }

        int ma,mb,mc,md;
        ma = mb = mc = md = INT_MAX;

        if(d >= 0) 
            md = 17-d-1;
        if (c >= 0)
            mc = 17 - c - 1;
        if (b >= 0)
            mb = 17 - b - 1;
        if (a >= 0)
            ma = 17 - a - 2;
        
        int ans = INT_MAX;
        ans = min(ans, ma);
        ans = min(ans, mb);
        ans = min(ans, mc);
        ans = min(ans, md);

        cout << ans << endl;
    }  
}