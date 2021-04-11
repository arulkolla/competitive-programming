#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, k;
	cin >> n >> k;
	if (k > (n - 1) / 2) {cout << -1 << endl; return;}
	deque<int> d;
	for (int i = 1; i <= n; i++) {
		d.push_back(i);
	}
	vector<int> res;
	for (int i = 0; i < k; i++) {
		res.push_back(d.front());
		res.push_back(d.back());
		d.pop_front();
		d.pop_back();
	}
	while (!d.empty()) {
		res.push_back(d.front());
		d.pop_front();
	}
	for (int i : res) {
		cout << i << ' ';
	}
	cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}