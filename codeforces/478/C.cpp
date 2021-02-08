#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
    long long r, g, b;
    cin >> r >> g >> b;
    long long v = min(r + g, min(g + b, b + r));
    cout << min((r + g + b) / 3, v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("sample.in", "r", stdin); freopen("sample.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}