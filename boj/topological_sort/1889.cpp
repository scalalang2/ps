#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 간선이 2개 밖에 없기 때문에
    // 가장 작은 간선이 2 이면서 2보다 높은 간선을 가진 애는 존재할 수 없음 
    // 그냥 2보다 작은 정점의 간선을 삭제시키면 된다.
    // 이게 왜 메모리 초과..? 흠..

    int N;
    cin >> N;
    vector<pair<int, int>> pp(N+1);
    vector<int> in(N+1);
    vector<bool> visited(N+1, false);
    fill(in.begin(), in.end(), 0);
    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        pp[i+1] = {a,b};
        in[a]++;
        in[b]++;
    }

    priority_queue<int> q;
    for(int i = 1; i <= N; i++) {
        if(in[i] < 2) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int node = q.top();
        q.pop();
        if(visited[node]) continue;
        visited[node] = true;

        pair<int,int> p = pp[node];
        in[p.first]--;
        in[p.second]--;
        if(in[p.first] < 2) {
            q.push(p.first);
        }
        if(in[p.second] < 2) {
            q.push(p.second);
        }
    }

    int cnt = 0;
    string ans = "";
    for(int i = 1; i <= N; i++) {
        if(in[i] == 2) {
            cnt++;
            ans += to_string(i) + " ";
        }
    }
    cout << cnt << endl;
    cout << ans << endl;

    return 0;
}