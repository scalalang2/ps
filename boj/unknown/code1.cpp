#include <iostream>

using namespace std;

const int sqrtN = 500;
int N, K, a[200020], ans, b[500];

void upd(int l, int r, int x) {
   while (l <= r && l % sqrtN) a[l++] += x;
   while (l <= r && (r + 1) % sqrtN) a[r--] += x;
   while (l <= r) b[l / sqrtN] += x, l += sqrtN;
}

int main() {
   freopen("input.txt", "r", stdin);
   cin >> N >> K;
   string s; cin >> s;
   N = (int)s.size();
   for (int i = 0; i < N; i++) {
      if (s[i] == 'R') a[i] = 0;
      else if (s[i] == 'G') a[i] = 1;
      else a[i] = 2;
   }


   for (int i = 0; i + K - 1 < N; i++) {
      if ((a[i] + b[i / sqrtN]) % 3 == 0) continue;
      ans += 3 - ((a[i] + b[i / sqrtN]) % 3);
      if (i + K - 1 < N) upd(i, i + K - 1, 3 - ((a[i] + b[i / sqrtN]) % 3));
   }
   
   for (int i = 0; i < N; i++)
      if ((a[i] + b[i / sqrtN]) % 3 != 0) 
         return cout << -1, 0;
   cout << ans;
}