#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100001;
int N;
string A, B;
int AA[MAXN] = {0};
int BB[MAXN] = {0};

int ctoi(char c) {
    if(c == '0') return -1;
    else return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    cin >> A >> B;

    for(int i = 0; i < N; i++) {
        AA[i] = ctoi(A[i]);
        BB[i] = ctoi(B[i]);
    }

    bool correct_a = true;
    bool correct_b = true;
    int ans_a = 0;
    int ans_b = 0;

    // 먼저 안키고 1번부터 시작하는 경우
    for(int i = 1; i < N; i++) {
        if(AA[i-1] != BB[i-1]) {
            AA[i-1] *= -1;
            AA[i] *= -1;
            if(i+1 < N) AA[i+1] *= -1;
            ans_a++;
        }
        if(i == N-1 && AA[i] != BB[i]) {
            correct_a = false;
        }
    }

    for (int i = 0; i < N; i++){
        AA[i] = ctoi(A[i]);
    }

    ans_b++;
    AA[0] *= -1;
    AA[1] *= -1;
    for (int i = 1; i < N; i++) {
        if (AA[i - 1] != BB[i - 1]) {
            AA[i - 1] *= -1;
            AA[i] *= -1;
            if (i + 1 < N)
                AA[i + 1] *= -1;
            ans_b++;
        }
        if (i == N - 1 && AA[i] != BB[i]) {
            correct_b = false;
        }
    }

    if(correct_a && correct_b) cout << min(ans_a, ans_b);
    else if(correct_a) cout << ans_a;
    else if(correct_b) cout << ans_b;
    else cout << -1;

    return 0;
}