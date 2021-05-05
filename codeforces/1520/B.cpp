#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
    long long n;
    cin >> n;
    long long len = to_string(n).length(), sz = 0, pow10 = 1;
    for (int i = 0; i < len; i++) {
        sz += pow10;
        pow10 *= 10ll;
    }
    cout << 9 * (len - 1) + (n / sz) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}