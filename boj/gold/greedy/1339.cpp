#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using p = pair<int, char>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    vector<string> words;
    vector<p> pp;
    int a[27];
    fill(a, a + 27, 0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        string word;
        cin >> word;
        words.push_back(&word[0]);
        for(int j = 0; j < word.length(); j++) {
            a[word[j] - 'A'] += pow(10, word.length()-j-1);
        }
    }

    sort(a, a + 27, greater<int>());
    int ans = 0;
    int k = 9;
    for(int i = 0; i < 27; i++) {
        if(a[i] != 0) {
            ans += a[i] * k;
            k--;
        }
    }
    cout << ans << endl;

    return 0;
}            