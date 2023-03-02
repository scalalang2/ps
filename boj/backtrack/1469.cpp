#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;
int ans[100];
int visited[17];

void search(int idx) {
    if(idx == n*2) {
        for(int i = 0; i < n*2; i++) {
            cout << ans[i] << " ";
        }
        exit(0);
    }

    if(ans[idx] != -1) {
        search(idx+1);
        return;
    }

    for(int i = 0; i < n; i++) {
        if(visited[arr[i]] == 1) continue;
        if(idx + arr[i] + 1 > n * 2) continue;
        if(ans[idx + arr[i] + 1] != -1) continue;

        visited[arr[i]] = 1;
        ans[idx] = arr[i];
        ans[idx + arr[i] + 1] = arr[i];
        search(idx+1);
        visited[arr[i]] = 0;
        ans[idx] = -1;
        ans[idx + arr[i] + 1] = -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(ans, -1, sizeof(ans));

    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    search(0);

    cout << -1 << endl;

    return 0;
}