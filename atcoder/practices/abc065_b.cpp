#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v;
    vector<bool> visited;
    v.resize(n+1);
    visited.reserve(n+1);
    for(int i = 1; i <= n; i++)
        cin >> v[i];

    int ans = 0;
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while(q.size())
    {
        int cur = q.front();
        q.pop();
        if(visited[v[cur]]) {
            cout << -1 << endl;
            return 0;
        }
        if(v[cur] == 2) {
            cout << ans+1 << endl;
            return 0;
        }
        visited[v[cur]] = true;
        q.push(v[cur]);
        ans++;
    }

    cout << -1 << endl;

    return 0;
}