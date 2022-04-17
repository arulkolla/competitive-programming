#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, r, b;
	cin >> n >> r >> b;
	// split r into b + 1 parts as equal as possible
	vector<int> v;
	if (r % (b + 1) == 0) {
		int tot = 0;
		while (tot < r) {
			v.push_back(r / (b + 1));
			tot += r / (b + 1);
		}
	}
	else {
		int tot = 0;
		for (int i = 0; i < b + 1; i++) {
			v.push_back(r / (b + 1));
			tot += r / (b + 1);
		}
		for (int i = 0; i < v.size(); i++) {
			if (tot >= r) {break;}
			else {v[i]++; tot++;}
		}
		// for (int i : v) {
			// cout << i << ' ';
		// }
	}
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i]; j++) {cout << 'R';}
		if (i != v.size() - 1) {cout << 'B';}
	}
	cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}