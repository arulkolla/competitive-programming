#include <bits/stdc++.h>

using namespace std;

const int MAX = 500007;
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    pair<int, int> a[MAX];
    for (int i = 0; i < n; i++) {
        cin >> a[i].second >> a[i].first;
    }
    int curr = 0, res = 0;
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        if (a[i].second > curr) {
            curr = a[i].first;
            res++;
        }
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}