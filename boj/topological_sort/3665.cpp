#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n;
        vector<vector<int>> E(n);
        vector<int> score(n);
        vector<int> in(n);
        for(int i = 0; i < n; i++) {
            E[i].resize(n);
            cin >> score[i];
        }

        // 하 입력값으로 들어온 성적이
        // i 번째 팀이 score[i] 라는게 아니라
        // 그냥 1등 팀부터 팀번호를 준거구나 에라이...
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                E[score[i]-1][score[j]-1] = 1;
                in[score[j]-1]++;
            }
        }

        cin >> m;
        while(m--) {
            int u,v;
            cin >> u >> v;
            u--;v--;
            if(E[u][v] == 1) {
                E[u][v] = 0;
                E[v][u] = 1;
                in[v]--;
                in[u]++;
            } else {
                E[u][v] = 1;
                E[v][u] = 0;
                in[v]++;
                in[u]--;
            }
        }

        vector<int> ans;

        queue<int> Q;
        for(int i = 0; i < n; i++) {
            if(in[i] == 0) Q.push(i);
        }

        int rank = 0;
        for(int i = 0; i < n; i++) {
            if(Q.empty()) {
                cout << "IMPOSSIBLE" << endl;
                goto ENDLOOP;
            }
            if(Q.size() >= 2) {
                cout << "?" << endl;
                goto ENDLOOP;
            }

            int curr = Q.front();
            Q.pop();
            ans.push_back(curr);
            rank++;
            for(int j = 0; j < n; j++) {
                if(E[curr][j] == 1) {
                    in[j]--;
                    if(in[j] == 0) Q.push(j);
                }
            }
        }

        for(int i = 0; i < n; i++) {
            cout << ans[i]+1 << " ";
        }
        cout << endl;

        ENDLOOP:;
    }
    return 0;
}