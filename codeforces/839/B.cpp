#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, k;
	cin >> n >> k;
	int a[k + 7];
	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}
	sort(a, a + k, greater<int>());
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		pq.push(2);
		pq.push(4);
		pq.push(2);
	}
	int curr = 0;
	while (true) {
		int now = pq.top();
		pq.pop();
		int mn = min(now, a[curr]);
		now -= mn;
		a[curr] -= mn;
		if (a[curr] == 0) {curr++;}
		if (now != 0) {
			if (now - 1 > 0) {pq.push(now - 1);}
		}
		if (curr == k) {cout << "YES" << endl; return;}
		if (pq.empty()) {cout << "NO" << endl; return;}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}