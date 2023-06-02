#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

string next(string s) {
    vector<int> nums = vector<int>(s.size());
    for(int i = 0; i < s.size(); i++)
        nums[i] = s[i] - '0';

    bool f = false;
    for(int i = s.size()-1; i > 0; i--) {
        int v = 10;
        int idx = -1;
        for(int j = i + 1; j < s.size(); j++){
            if(nums[i] < nums[j] && nums[j] < v) {
                v = nums[j];
                idx = j;
            }
        }
        if(idx != -1) {
            swap(nums[i], nums[idx]);
            sort(nums.begin() + i+1, nums.end());
            f = true;
            break;
        }
    }

    if(!f) return "BIGGEST";

    string res = "";
    for(int i = 0; i < nums.size(); i++)
        res += nums[i] + '0';

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 다음 수 라는 건 수의 구성이 같은 수들 중에 현재 값보다 큰 것
    // 현재 값보다 크기 위한 조건..?

    // S[i] 에 대해서 바로 다음의 가까운 큰 수가 존재해야 함
    // 이걸 뒤에서 부터 처리하고 reverse 하는 거지

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        cout << next(s) << "\n";
    }

    return 0;
}