#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    bool mp[37] = {};
    string s;
    cin >> s;
    mp[s[0] - 'A'] = true;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i - 1]) {
            if (mp[s[i] - 'A']) {cout << "NO" << endl; return;}
            mp[s[i] - 'A'] = true;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}