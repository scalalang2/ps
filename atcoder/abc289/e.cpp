#include<bits/stdc++.h>

using namespace std;

int T, N, M;
int colors[2001];
int visited[2001][2001];
vector<vector<int>> G;

struct Node {
    int ta, ao, cnt;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    while(T --> 0) {
        cin >> N >> M;
        G = vector<vector<int>>(N+1);
        for (int i = 0; i < 2001; i++) {
            for (int j = 0; j < 2001; j++) {
                visited[i][j] = 0;
            }
        }
        for(int i = 1; i <= N; i++) {
            cin >> colors[i];
        }
        for(int i = 1; i <= M; i++) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        deque<Node> q;
        q.push_back({1, N, 0});
        visited[1][N] = 1;
        int ans = -1;
        while(!q.empty()) {
            Node curr = q.front();
            q.pop_front();
            if(curr.ta == N && curr.ao == 1) {
                ans = curr.cnt;
                break;
            }

            for(auto x : G[curr.ta]) {
                for (auto y : G[curr.ao]) {
                    if(x == y) continue;
                    if(colors[x] == colors[y]) continue;
                    if(visited[x][y]) continue;
                    visited[x][y] = 1;

                    q.push_back({x, y, curr.cnt + 1});
                }
            }
        }

        cout << ans << endl;;
    }
    return 0;
}