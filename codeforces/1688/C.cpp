#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	char r = '!';
	for (int i = 0; i <= 2 * n; i++) {
		string s; cin >> s;
		for (char c : s) {r ^= c;}
	}
	cout << (char)(r ^ '!') << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}