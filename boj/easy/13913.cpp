#include<bits/stdc++.h>

using namespace std;

int A, B;
bool visited[100001];
int path[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 흠왔던 경로로 가라..
    cin >> A >> B;
    queue<pair<int, int>> q;
    q.push({A, 0});

    memset(path, 0, sizeof(path));
    path[A] = A;
    visited[A] = true;

    if(A == B) {
        cout << 0 << endl;
        cout << A;
        return 0;
    }

    while(!q.empty()) {
        auto d = q.front(); q.pop();
        if(d.first == B) {
            cout << d.second << endl;
            vector<int> ans;
            int i = d.first;
            ans.push_back(i);
            while(path[i] != A) {
                i = path[i];
                ans.push_back(i);
            }
            ans.push_back(A);
            for(int i = ans.size()-1; i >= 0; i--) {
                cout << ans[i] << " ";
            }
            return 0;
        }

        // 방문한 적이 있으면 무시
        if(d.first < 0 || d.first > 100000) continue;
        
        if(d.first-1 >= 0 && !visited[d.first-1]) {
            q.push({d.first - 1, d.second + 1});
            path[d.first - 1] = d.first;
            visited[d.first - 1] = true;
        }

        if (d.first+1 <= 100000 && !visited[d.first + 1]) {
            q.push({d.first + 1, d.second + 1});
            path[d.first + 1] = d.first;
            visited[d.first + 1] = true;
        }

        if (d.first*2 <= 100000 && !visited[d.first*2]) {
            q.push({d.first *2, d.second + 1});
            path[d.first *2] = d.first;
            visited[d.first *2] = true;
        }
    }

    return 0;
}