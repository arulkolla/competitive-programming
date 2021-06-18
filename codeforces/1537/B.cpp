#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long dist(pair<long long, long long> p, pair<long long, long long> q) {
	return abs(p.first - q.first) + abs(p.second - q.second);
}

void solve() {
	long long n, m, ai, aj;
	cin >> n >> m >> ai >> aj;
	pair<long long, long long> ant = make_pair(ai, aj);
	pair<long long, long long> a1 = make_pair(1, 1), a2 = make_pair(n, m);
	pair<long long, long long> b1 = make_pair(1, m), b2 = make_pair(n, 1);
	long long d1 = dist(ant, a1) + dist(ant, a2) + dist(a1, a2);
	long long d2 = dist(ant, b1) + dist(ant, b2) + dist(b1, b2);
	if (d1 > d2) {
		cout << 1 << ' ' << 1 << ' ' << n << ' ' << m << endl;
	}
	else {
		cout << 1 << ' ' << m << ' ' << n << ' ' << 1 << endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}