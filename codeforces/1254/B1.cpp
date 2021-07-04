#include <bits/stdc++.h>

using namespace std;

const int MAX = 100007;
const int MOD = 1000000007;

int n, a[MAX];

long long ans(long long mn) {
	int curr = 0;
	vector<long long> now;
	long long res = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {curr++; now.push_back((long long)i);}
		if (curr == mn) {
			for (long long i : now) {
				res += abs(now[(now.size()) / 2] - i);
			}
			now.clear();
			curr = 0;
		}
	}
	return res;
}

void solve() {
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum == 1) {cout << -1 << endl; return;}
	long long res = 100000000000007ll;
	for (int i = 1; i * i <= sum; i++) {
		if (sum % i == 0) {
			if (i != 1) {res = min(res, ans(i));}
			if (sum / i != 1) {res = min(res, ans(sum / i));}
		}
	}
	cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}