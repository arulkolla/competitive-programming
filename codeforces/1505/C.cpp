#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

int f(char c) {
    return (c - 'A');
}

void solve() {
    string s;
    cin >> s;
    for (int i = 2; i < s.size(); i++) {
        if (abs(f(s[i]) - f(s[i - 1]) - f(s[i - 2])) % 26 != 0) {
            // cout << abs(f(s[i]) - f(s[i - 1]) - f(s[i - 2])) << ' ';
            cout << "NO" << endl; return;
            
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("sample.in", "r", stdin); freopen("sample.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}