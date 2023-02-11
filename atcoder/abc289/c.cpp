#include<bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> v;
bool visited[11] = {false};
bool cnt[11] = {false};

bool count_all() {
    set<int> s;
    for(int i = 1; i <= M; i++) {
        if(visited[i]) {
            for(auto x : v[i]) {
                s.insert(x);
            }
        }
    }

    return s.size() == N;
}

int dfs(int curr) {
    if(curr == M+1) {
        if(count_all()) return 1;
        else return 0;
    }

    visited[curr] = true;
    int a = dfs(curr + 1);
    visited[curr] = false;
    int b = dfs(curr + 1);

    return a + b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    v.resize(M+1);

    for(int i = 1; i <= M; i++) {
        int s;
        cin >> s;
        v[i].resize(s);
        for(int j = 0; j < s; j++) {
            cin >> v[i][j];
        }
    }

    cout << dfs(1) << endl;
    return 0;
}