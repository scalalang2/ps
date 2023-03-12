#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n+1);    
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    set<int> s;
    vector<int> ans;

    for(int i = 1; i <= n; i++) {
        if(s.find(i) == s.end()) {
            s.insert(arr[i]);
        }
    }

    for(int i = 1; i <= n; i++) {
        if(s.find(i) == s.end()) {
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}