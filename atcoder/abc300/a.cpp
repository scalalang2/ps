#include<bits/stdc++.h>

using namespace std;

int n, a, b;
vector<int> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> a >> b;
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    int idx = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == a + b) {
            idx = i + 1;
        }
    }

    cout << idx << endl;

    return 0;
}