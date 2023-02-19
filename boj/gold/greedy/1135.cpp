#include<bits/stdc++.h>

using namespace std;

using P = pair<int, int>;

vector<vector<int>> G;
int n;
int ans = 0;

struct Cmp {
    bool operator()(
        P const& a,
        P const& b
    ) {
        if(a.first == b.first) return a.first > b.first;
        else return a.second > b.second;
    }
};

int 부하_놈들_개수(int curr) {
    int ans = G[curr].size();
    for (int i = 0; i < G[curr].size(); i++) {
        ans += 부하_놈들_개수(G[curr][i]);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    G.resize(n);

    // 딸린 전체 부하가 많은 순으로 취한다?
    // 

    for(int i = 0; i < n; i++) {
        int parent;
        cin >> parent;
        if(parent != -1) G[parent].push_back(i);
    }

    priority_queue<P, vector<P>, Cmp> Q;
    Q.push(P(0, 0));
    while(!Q.empty()) {
        P curr = Q.top();
        Q.pop();

        ans = max(ans, curr.first);

        vector<P> vv;
        for(int i = 0; i < G[curr.second].size(); i++) {
            int nxt = G[curr.second][i];
            vv.push_back(P(G[nxt].size(), nxt));
        }
        sort(vv.begin(), vv.end(), greater<P>());

        for(int i = 0; i < vv.size(); i++) {
            Q.push(P(i + 1 + curr.first, vv[i].second));
        }
    }

    cout << ans << endl;

    return 0;
}