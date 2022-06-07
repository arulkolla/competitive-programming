#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int l = 0, r = k - 1, cnt = 0, mx;
	for (int i = l; i <= r; i++) {cnt += (s[i] == 'B');}
	mx = cnt;
	for (int i = k; i < n; i++) {
		cnt -= (s[l] == 'B');
		l++; r++;
		cnt += (s[r] == 'B');
		mx = max(mx, cnt);
	}
	cout << max(k - mx, 0) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}