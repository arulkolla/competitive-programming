#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long long n;
	cin >> n;
	long long res = 0;
	vector<pair<int, long long>> v;
	for (long long i = 2; i * i <= n; i++) {
		int pos = 1;
		while (n % i == 0) {
			v.emplace_back(pos, i);
			pos++;
			n /= i;
		}
	}
	if (n > 1) {v.emplace_back(1, n);}
	sort(v.begin(), v.end());
	int curr = 1;
	long long now = 1;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].first == curr) {now *= v[i].second;}
		else {res += now; now = v[i].second; curr++;}
	}
	res += now;
	cout << res << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}