#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	long long l, r;
	cin >> n >> l >> r;
	bool ok = true;
	vector<long long> v;
	for (int i = 1; i <= n; i++) {
		long long nl = l, nr = r - (r % i);
		if ((l + i) % i != 0) {nl += (i - ((l + i) % i));}
		if (nl > nr) {ok = false;}
		else {v.push_back(nr);}
	}	
	if (ok) {
		cout << "YES\n";
		for (long long x : v) {cout << x << ' ';}
		cout << '\n';
	}
	else {
		cout << "NO\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}