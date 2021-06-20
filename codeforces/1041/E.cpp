#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int cnt[n + 7];
	for (int i = 1; i <= n; i++) {
		cnt[i] = 0;
	}
	int ai, bi;
	for (int i = 0; i < n - 1; i++) {
		cin >> ai >> bi;
		if (bi != n) {cout << "NO" << endl; return;}
		cnt[ai]++;
	}
	int tree[n + 7];
	for (int i = 0; i < n; i++) {
		tree[i] = 0;
	}
	tree[0] = n;
	int last = 0;
	for (int i = n - 1; i >= 1; i--) {
		last += cnt[i];
		if (cnt[i] > 0) {
			tree[last] = i;
		}
		else {
			bool ok = false;
			for (int j = 0; j < last; j++) {
				if (tree[j] == 0) {tree[j] = i; ok = true; break;}
			}
			if (!ok) {cout << "NO" << endl; return;}
		}
	}
	cout << "YES" << endl;
	for (int i = 1; i < n; i++) {
		cout << tree[i - 1] << ' ' << tree[i] << endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}