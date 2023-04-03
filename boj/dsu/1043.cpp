#include<bits/stdc++.h>

using namespace std;

int n, m;

// imp 중요한 인물들 
set<int> imp;
vector<int> queries[51];
int parent[51];

int find(int x) {
    if(parent[x] == x) return x;
    parent[x] = find(parent[x]);
    return parent[x];
}

void merge(int a, int b) {
    int u = find(a);
    int v = find(b);
    if(u == v) return;
    int p;
    if(imp.find(u) != imp.end()) p = u;
    else if(imp.find(v) != imp.end()) p = v;
    else p = u;

    parent[u] = p;
    parent[v] = p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i <= 50; i++) {
        parent[i] = i;
    }

    int k;
    cin >> k;
    for(int i = 0; i < k; i++) {
        int x;
        cin >> x;
        imp.insert(x);
    }

    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        for(int j = 0; j < x; j++) {
            int y;
            cin >> y;
            queries[i].push_back(y);
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 1; j < queries[i].size(); j++) {
            merge(queries[i][j-1], queries[i][j]);
        }
    }

    int ans = 0; 
    for(int i = 0; i < m; i++) {
        bool found = false;
        for(int j = 0; j < queries[i].size(); j++) {
            if(imp.find(find(queries[i][j])) != imp.end()) {
                found = true;
                break;
            }
        }
        if(!found) ans++;
    }

    cout << ans << endl;

    return 0;
}

