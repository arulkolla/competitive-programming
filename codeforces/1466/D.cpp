
// Problem: D. 13th Labour of Heracles
// Contest: Codeforces - Good Bye 2020
// URL: https://codeforces.com/contest/1466/problem/D
// Memory Limit: 256 MB
// Time Limit: 2500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	long long sum = 0;
	int w[n + 7], cnt[n + 7];
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
		cnt[i] = 0;
		sum += w[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		cnt[u]++;
		cnt[v]++;
	}
	priority_queue<long long> pq;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < cnt[i]; j++) {
			pq.push(w[i]);
		}
	}
	cout << sum << " ";
	for (int i = 1; i < n - 1; i++) {
		sum += pq.top();
		pq.pop();
		cout << sum << " ";
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