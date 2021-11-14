#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int> > a, b;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a.push(x);
	}
	for (int i = 0; i < n; i++) {
		cin >> x;
		b.push(x);
	}
	int af, bf;
	while (!a.empty()) {
		af = a.top();
		bf = b.top();
		a.pop(); b.pop();
		if (!(af == bf || af + 1 == bf)) {cout << "NO\n"; return;}
	}
	cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}