#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long f(long long x) {
    long long s = 0;
    while (x != 0) {
        s = s + x % 10;
        x = x / 10;
    }
    return s;
}

void solve() {
    long long s;
    cin >> s;
    cout << f(f(f(f(s))));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("sample.in", "r", stdin); freopen("sample.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}