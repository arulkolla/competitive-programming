#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long gcd(long long a, long long b) {
	if (b == 0) {return a;}
	return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
	return (a * b) / gcd(a, b);
}

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int a[n + 1];
	bool vis[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		vis[i] = false;
	}	
	vector<string> v;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			int curr = i;
			string now = "";
			while (!vis[curr]) {
				vis[curr] = true;
				now += s[curr - 1];
				curr = a[curr];
			}
			v.push_back(now);
		}
	}
	vector<long long> sz;
	for (string s : v) {
		string t = s;
		rotate(t.begin(), t.begin() + 1, t.end());
		long long move = 1;
		while (t != s) {
			rotate(t.begin(), t.begin() + 1, t.end());
			move++;
		}
		sz.push_back(move);
	}
	if (sz.size() == 1) {cout << sz[0] << '\n'; return;}
	long long l = lcm(sz[0], sz[1]);
	for (int i = 2; i < sz.size(); i++) {l = lcm(l, sz[i]);}
	cout << l << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}