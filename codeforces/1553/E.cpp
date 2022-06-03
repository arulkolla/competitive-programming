#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, k;
	cin >> n >> k;
	int a[n], d[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		d[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		d[(2 * n + i - a[i] + 1) % n]++;
	}
	vector<int> good;
	for (int i = 0; i < n; i++) {
		if (d[i] >= n - 2 * k) {good.push_back(i);}
	}
	int id[n];
	bool vis[n];
	vector<int> res;
	for (int rot : good) {
		for (int i = 0; i < n; i++) {id[i] = a[i] - 1; vis[i] = false;}
		rotate(id, id + rot, id + n);
		int cnt = n;
		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				cnt--;
				int curr = i;
				while (!vis[curr]) {
					vis[curr] = true;
					curr = id[curr];
				}
			}
		}
		if (cnt <= k) {res.push_back(rot);}
	}
	sort(res.begin(), res.end());
	cout << res.size() << ' '; for (int i : res) {cout << i << ' ';} cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}