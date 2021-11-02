#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int ta[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> ta[i];
	}
	string s;
	cin >> s;
	pair<char, int> a[n + 7];
	for (int i = 0; i < n; i++) {
		a[i] = make_pair(s[i], ta[i]);
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		if (a[i].first == 'B') {
			if (a[i].second < i + 1) {cout << "NO\n"; return;}
		}
		else {
			if (a[i].second > i + 1) {cout << "NO\n"; return;}
		}
	}	
	cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}