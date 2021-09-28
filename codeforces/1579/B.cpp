#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[n + 7], b[n + 7];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	vector<pair<pair<int, int>, int> > v;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (b[i] == a[j]) {
				rotate(a + i, a + j, a + j + 1);
				if (j != i) {
					v.push_back(make_pair(make_pair(i, j), j - i));
				}
				break;
			}
		}
	}
	cout << v.size() << '\n';
	for (auto p : v) {
		cout << p.first.first << ' ' << p.first.second << ' ' << p.second << '\n';
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}