#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < n - 2; i++) {
		if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
			cnt++;
		}
	}
	for (int i = 0; i < q; i++) {
		int x; char c;
		cin >> x >> c;
		x--;
		int bef = 0, aft = 0;
		if (x >= 2 && s[x - 2] == 'a' && s[x - 1] == 'b' && s[x] == 'c') {
			bef++;
		}
		if (x >= 1 && x < n - 1 && s[x - 1] == 'a' && s[x] == 'b' && s[x + 1] == 'c') {
			bef++;
		}
		if (x < n - 2 && s[x] == 'a' && s[x + 1] == 'b' && s[x + 2] == 'c') {
			bef++;
		}
		s[x] = c;
		if (x >= 2 && s[x - 2] == 'a' && s[x - 1] == 'b' && s[x] == 'c') {
			aft++;
		}
		if (x >= 1 && x < n - 1 && s[x - 1] == 'a' && s[x] == 'b' && s[x + 1] == 'c') {
			aft++;
		}
		if (x < n - 2 && s[x] == 'a' && s[x + 1] == 'b' && s[x + 2] == 'c') {
			aft++;
		}
		cnt += (aft - bef);
		cout << cnt << '\n';
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}