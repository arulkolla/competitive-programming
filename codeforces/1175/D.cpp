#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, k;
	cin >> n >> k;
	long long a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	reverse(a, a + n);
	priority_queue<long long> pq;
	long long curr = 0;
	for (int i = 0; i < n - 1; i++) {
		curr += a[i];
		pq.push(curr);
	}
	long long res = curr + a[n - 1];
	for (int i = 0; i < k - 1; i++) {
		res += pq.top();
		pq.pop();
	}
	cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}