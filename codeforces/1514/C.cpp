#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long gcd(long long a, long long b) {
	if (b == 0) {return a;}
	return gcd(b, a % b);
}

void solve() {
	long long n;
	cin >> n;
	vector<long long> res, alt;
	for (long long i = 1; i <= n - 1; i++) {
		if (gcd(i, n) == 1) {
			res.push_back(i);
		}
	}
	long long prod = 1;
	for (long long i : res) {
		prod *= i;
		prod %= n;
	}
	if (prod != 1) {
		cout << res.size() - 1 << endl;
		for (long long i : res) {
			if (i != n - 1) {
				cout << i << ' ';
			}
		}
	}
	else {
		cout << res.size() << endl;
		for (long long i : res) {
			cout << i << ' ';
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}