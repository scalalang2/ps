#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  vector<vector<int>> S(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
    S[i].resize(A[i]);
    for (int j = 0; j < A[i]; j++){
      cin >> S[i][j];
      S[i][j]--;
    }
  }
  vector<vector<int>> E(N + M);
  for (int i = 0; i < N; i++){
    for (int j = 0; j < A[i]; j++){
      E[i].push_back(N + S[i][j]);
      E[N + S[i][j]].push_back(i);
    }
  }
  vector<int> d(N + M, -1);
  d[N] = 0;
  queue<int> Q;
  Q.push(N);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (int w : E[v]){
      if (d[w] == -1){
        d[w] = d[v] + 1;
        Q.push(w);
      }
    }
  }
  if (d[N + M - 1] == -1){
    cout << -1 << endl;
  } else {
    cout << d[N + M - 1] / 2 - 1 << endl;
  }
}