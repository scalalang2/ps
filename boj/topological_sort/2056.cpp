#include<bits/stdc++.h>

using namespace std;

const int MAXN = 10001;
int N;
vector<int> adj[MAXN];
int costs[MAXN];
int dp[MAXN];
bool visited[MAXN];
stack<int> st;

void dfs(int node) {
    visited[node] = true;
    for(auto nxt : adj[node]) {
        if(visited[nxt]) continue;
        dfs(nxt);
    }
    st.push(node);
}

void search() {
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        if(dp[node] == 0) dp[node] = costs[node];
        for(auto nxt : adj[node]) {
            dp[nxt] = max(dp[nxt], dp[node] + costs[nxt]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;

    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= N; i++) {
        int cost;
        int num;
        cin >> cost >> num;
        costs[i] = cost;
        while(num--) {
            int x;
            cin >> x;
            adj[x].push_back(i);
        }
    }

    for(int i = 1; i <= N; i++) {
        if(visited[i]) continue;
        dfs(i);
    }

    search();

    int ans = 0;
    for(int i = 1; i <= N; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;


    return 0;
}