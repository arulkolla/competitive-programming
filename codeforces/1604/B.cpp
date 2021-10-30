#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[n + 7];
	set<int> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s.insert(a[i]);
	}
	if ((n % 2 == 0) || (!is_sorted(a, a + n)) || (s.size() != n)) {cout << "YES\n"; return;}
	else {cout << "NO\n"; return;}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}