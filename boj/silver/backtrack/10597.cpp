#include<bits/stdc++.h>

using namespace std;

set<int> s;
vector<int> ans;

void find(string ss) {
    if (ss.size() == 0) {
        int st = 1;
        for (auto x : s) {
            if(x != st) {
                return;
            }
            st++;
        }
        for (auto i : ans) {
            cout << i << " ";
        }
        exit(0);
    }

    for (int i = 1; i <= 2; i++) {
        if (ss.size() < i) continue;
        string tmp = ss.substr(0, i);
        int num = stoi(tmp);
        if (num > 50 || num < 1) continue;
        if (s.count(num)) continue;
        s.insert(num);
        ans.push_back(num);
        find(ss.substr(i));
        s.erase(num);
        ans.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string t;
    cin >> t;

    find(t);


    return 0;
}