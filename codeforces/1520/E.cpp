#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v;
    int curr = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            v.push_back(i - curr);
            curr++;
        }
    }
    if (v.empty()) {cout << 0 << endl; return;}
    sort(v.begin(), v.end());
    int med;
    if (v.size() % 2 == 1) {
        med = v[(v.size() - 1) / 2];
    }
    else {
        med = (v[(v.size()) / 2] + v[(v.size() - 1) / 2]) / 2;
    }
    long long res = 0;
    curr = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            res += (long long)abs(med - i + curr);
            curr++;
        }
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}