#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	vector<int> ones;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a % 2 == 1) {ones.push_back(i);}
	}
	long long res = 0;
	if (n % 2 == 1) {
		if ((int)ones.size() != (n / 2) && (int)ones.size() != (n / 2 + 1)) {
			cout << -1 << '\n'; return;
		}
		else if ((int)ones.size() == (n / 2)) {
			for (int i = 0; i < (int)ones.size(); i++) {
				res += (long long)(abs(2 * i + 1 - ones[i]));
			}
		}
		else {
			for (int i = 0; i < (int)ones.size(); i++) {
				res += (long long)(abs(2 * i - ones[i]));
			}
		}
	}
	else {
		if ((int)ones.size() != (n / 2)) {
			cout << -1 << '\n'; return;
		}
		long long v1 = 0, v2 = 0;
		for (int i = 0; i < (int)ones.size(); i++) {
			v1 += (long long)(abs(2 * i - ones[i]));
			v2 += (long long)(abs(2 * i + 1 - ones[i]));
		}
		res = min(v1, v2);
	}
	cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}