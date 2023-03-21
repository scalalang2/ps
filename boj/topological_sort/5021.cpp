#include<bits/stdc++.h>

using namespace std;

using pp = pair<int, double>;

int key = 0;
map<string, int> keys;
string root;
pp in[2000];
vector<int> G[2000];
set<int> candidates;

int add_key(string k) {
    if(keys.find(k) == keys.end()) {
        keys[k] = key;
        key++;
    }

    return keys[k];
}

bool is_candidate(int k) {
    return candidates.find(k) != candidates.end();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    cin >> root;
    int r = add_key(root);
    in[r].second = 1.0;

    for(int i = 0; i < n; i++) {
        string a, b, c;
        cin >> a >> b >> c;
        int u = add_key(a);
        int v = add_key(b);
        int z = add_key(c);
        in[u].first += 2;
        G[v].push_back(u);
        G[z].push_back(u);
    }

    for(int i = 0; i < m; i++) {
        string c;
        cin >> c;
        int u = add_key(c);
        candidates.insert(u);
    }

    queue<int> Q;
    for(int i = 0; i < key; i++) {
        if(in[i].first == 0) {
            Q.push(i);
        }
    }

    double max_rank = -1;
    int max_id = 0;

    for(int i = 0; i < key; i++) {
        int curr = Q.front(); Q.pop();
        for(auto child : G[curr]) {
            in[child].first--;
            in[child].second += in[curr].second;
            if(in[child].first == 0) {
                in[child].second /= 2.0;
                if(is_candidate(child) && in[child].second > max_rank) {
                    max_rank = in[child].second;
                    max_id = child;
                }
                Q.push(child);
            }
        }
    }

    for(auto it = keys.begin(); it != keys.end(); it++) {
        if(it->second == max_id) cout << it->first << endl;
    }


    return 0;
}