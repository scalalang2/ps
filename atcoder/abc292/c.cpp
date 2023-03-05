#include<bits/stdc++.h>

using namespace std;

int f(int i){
    int ret = 0;
    for (int j = 1; j * j <= i; j++) {
        if (i % j == 0) {
            ret++;
            if (j * j != i) ret++;
        }
    }
    return ret;
}

int main()
{
    int n, ans = 0;
    cin >> n;

    for (int i = 0; i <= n; i++) {
        int j = n - i;
        ans += f(i) * f(j);
    }

    cout << ans << endl;
    return 0;
}
