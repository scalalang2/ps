#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    int max_v = -1;
    int ans = -1;

    for(int i = 0; i < n; i++) {
        if(a[i] == t and b[i] > max_v) {
            max_v = b[i];
            ans = i + 1;
        }
    }
    if(ans != -1) {
        cout << ans << endl;
        return 0;
    }

    t = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] == t and b[i] > max_v)
        {
            max_v = b[i];
            ans = i + 1;
        }
    }

    cout << ans << endl;


    return 0;
}