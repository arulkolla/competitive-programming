#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	long long a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}	
	if (n % 2 == 0) {
		long long min = MOD;
		int minpos = -1;
		for (int i = 0; i < n; i++) {
			if (a[i] < min) {min = a[i]; minpos = i;}
		}
		cout << (minpos % 2 ? "Mike" : "Joe") << '\n';
	}
	else {
		cout << "Mike\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}