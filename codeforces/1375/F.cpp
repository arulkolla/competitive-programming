
// Problem: F. Integer Game
// Contest: Codeforces - Codeforces Global Round 9
// URL: https://codeforces.com/contest/1375/problem/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long a[7], b[7];

bool query(long long k) {
	cout << k << endl;
	long long v;
	cin >> v;
	if (v == 0) {return true;}
	a[v - 1] += k;
	for (int i = 0; i < 3; i++) {
		b[i] = a[i];
	}
	sort(b, b + 3);
	return false;
}

void solve() {
	cin >> a[0] >> a[1] >> a[2];
	cout << "First" << endl;
	for (int i = 0; i < 3; i++) {
		b[i] = a[i];
	}
	sort(b, b + 3);
	
	bool done = false;
	done = query(b[2]);
	if (done) {return;}
	done = query(2 * b[2] - b[1] - b[0]);
	if (done) {return;}
	done = query(b[1] - b[0]);
	if (done) {return;}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}