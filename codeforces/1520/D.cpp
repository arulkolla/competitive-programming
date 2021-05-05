#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    int a[n + 7];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= i;
    }
    sort(a, a + n);
    long long curr = 1;
    vector<long long> cnt;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {curr++;}
        else {cnt.push_back(curr); curr = 1;}
    }
    cnt.push_back(curr);
    long long res = 0;
    for (long long i : cnt) {
        res += (i * (i - 1)) / 2;
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}