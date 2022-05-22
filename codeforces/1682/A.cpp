#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int l = n / 2, r = n / 2;
	while (l - 1 >= 0 && s[l - 1] == s[n / 2]) {l--;}
	while (r + 1 < n && s[r + 1] == s[n / 2]) {r++;}
	cout << r - l + 1 << '\n'; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}