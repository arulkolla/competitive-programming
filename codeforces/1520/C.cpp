#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    if (n == 2) {cout << -1 << endl; return;}
    int curr1 = 1, curr2 = (n * n + 1) / 2 + 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 0) {cout << curr1 << ' '; curr1++;}
            else {cout << curr2 << ' '; curr2++;}
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}