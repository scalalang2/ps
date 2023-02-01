#include<bits/stdc++.h>

using namespace std;

using pp = pair<int, int>;

bool cmp(pp a, pp b) {
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        pp arr[101];
        for(int i = 0; i < n +1; i++) {
            arr[i] = make_pair(0,0);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n-1; j++) {
                int x;
                cin >> x;
                arr[x-1].first = x;
                arr[x-1].second += j;
            }
        }

        sort(arr, arr + n, cmp);

        for(int i = 0; i < n; i++) {
            cout << arr[i].first << " ";
        }
        cout << endl;
        
    }


    return 0;
}