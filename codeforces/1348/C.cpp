#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    int n, k;
    unordered_map<char, int> mp;
    set<char> thing;
    string s, ans;
    cin >> n >> k;
    cin >> s;
    sort(s.begin(), s.end());
    for (char ch : s) {
        mp[ch]++;
        thing.insert(ch);
    }
    if (k == 1) {
        cout << s << endl;
        return;
    }
    else if (s[k-1] != s[0]) {
        cout << s[k-1] << endl;
        return;
    }
    else if (thing.size() == 1) {
        int cnt = n/k + (n % k != 0);
        ans = string(cnt, s[0]);
        cout << ans << endl;
        return;
    }
    else if (mp[s[0]] == k && thing.size() == 2) {
        ans += s[0];
        int cnt = mp[s[k]]/k + (mp[s[k]] % k != 0);
        ans += string(cnt, s[k]);
        cout << ans << endl;
        return;
    }
    else {
        for (int i = k-1; i < n; ++i){
            ans += s[i];
        }
        cout << ans << endl;
        return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int i = 1; i <= tt; i++) {
        solve();
    }
//    solve();
}
