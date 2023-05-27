#include<bits/stdc++.h>

using namespace std;

int N, M;
vector<string> S;
vector<bool> visited;

int find_diff(string a, string b) {
    int ret = 0;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] != b[i]) ret++;
    }
    return ret;
}

void permute(int pos, int acc) {
    if(acc == N) {
        cout << "Yes";
        exit(0);
    }

    for(int i = 0; i < N; i++) {
        if(visited[i]) continue;
        if(pos == i) continue;

        if(find_diff(S[pos], S[i]) != 1) continue;
        visited[i] = true;
        permute(i, acc + 1);
        visited[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    visited.resize(N);
    for(int i = 0; i < N; i++) {
        string x;
        cin >> x;
        S.push_back(x);
    }

    for(int i = 0; i < N; i++) {
        visited[i] = true;
        permute(i, 1);
        visited[i] = false;
    }

    cout << "No";

    return 0;
}