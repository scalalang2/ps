#include<bits/stdc++.h>

using namespace std;

struct Schedule {
    int tab;
    int start;
    int end;
};

int N, K;
int arr[101];
Schedule schd[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> K;
    for(int i = 0; i < K; i++) cin >> arr[i];
    for(int i = 0; i < K; i++) {
        int j = i+1;
        for(; j < K; j++) {
            if(arr[j] == arr[i]) break;
        }
        schd[i].tab = arr[i];
        schd[i].start = i;
        schd[i].end = j;
    }

    // 멀티탭
    vector<int> v(N);
    int ans = 0;
    fill(v.begin(), v.end(), -1);

    for(int i = 0; i < K; i++) {
        bool filled = false;
        for(int j = 0; j < N; j++) {
            if(v[j] == -1) {
                v[j] = i;
                filled = true;
                break;
            }
            if(schd[v[j]].tab == schd[i].tab) {
                v[j] = i;
                filled = true;
                break;
            }
        }
        if(filled) continue;

        // 뭔가 뽑아야 함
        // 다음 번 등장이 가장 긴애를
        int ed = -101;
        int nxt = 0;
        for(int j = 0; j < N; j++) {
            if(schd[v[j]].end - i > ed) {
                ed = schd[v[j]].end - i;
                nxt = j;
            }
        }
        ans++;
        v[nxt] = i;
    }

    cout << ans << endl;


    return 0;
}