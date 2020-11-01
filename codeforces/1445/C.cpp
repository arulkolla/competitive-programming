
// Problem: C. Division
// Contest: Codeforces - Codeforces Round #680 (Div. 2, based on Moscow Team Olympiad)
// URL: https://codeforces.com/contest/1445/problem/C
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long long p, q;
	cin >> p >> q;
	if (p % q) {cout << p << endl; return;}
	vector<long long> facts;
	for (long long i = 2; i * i <= q; i++) {
		if (q % i == 0) {facts.push_back(i); facts.push_back(q/i);}
	}
	facts.push_back(q);
	sort(facts.begin(), facts.end());
	long long res = 1;
	for (long long i : facts) {
		long long curr = p;
		while (curr % q == 0) {
			curr /= i;
		}
		res = max(curr, res);
	}
	cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}