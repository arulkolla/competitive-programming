#include <bits/stdc++.h>

using namespace std;

const int MAX = 10007;
const int MOD = 1000000007;

void solve() {
    string s, s1, s2, s3;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (i % 2 == 0) {s1 += s[i];}
        else if (i % 2 == 1) {s2 += s[i];}
    }
    if (s2.empty()) {
        cout << stoi(s1) - 1; return;
    }
    cout << (stoi(s1) + 1) * (stoi(s2) + 1) - 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve(); cout << endl;}
    //solve();
}
