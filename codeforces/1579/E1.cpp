#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	deque<int> d;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (d.empty() || a > d.front()) {d.push_back(a);}
		else {d.push_front(a);}
	}
	for (int i : d) {
		cout << i << ' ';
	}
	cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}