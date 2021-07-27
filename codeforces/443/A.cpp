#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	char c;
	cin >> c;
	set<char> s;
	while (c != '}') {
		cin >> c;
		if (c != ',' && c != ' ' && c != '}') {
			s.insert(c);
		}
	}
	cout << s.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}