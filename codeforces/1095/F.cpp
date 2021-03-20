// Problem: F. Make It Connected
// Contest: Codeforces - Codeforces Round #529 (Div. 3)
// URL: https://codeforces.com/contest/1095/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

int a[MAX], sz[MAX], cnt[MAX];
bool head[MAX];
 
void init() {
	for (int i = 0; i < MAX; i++) {
		a[i] = i;
		sz[i] = 0;
		cnt[i] = 1;
		head[i] = true;
	}
}

int find(int p) {
	while (p != a[p]) {
		a[p] = a[a[p]];
		p = a[p];
	}
	return p;
}
 
bool connected(int p, int q) {
	return find(p) == find(q);
}
 
void join(int p, int q) {
	int i = find(p);
	int j = find(q);
	if (i != j) {
		if (sz[i] < sz[j]) {cnt[j] += cnt[i]; a[i] = j; head[i] = false;}
		else if (sz[i] > sz[j]) {cnt[i] += cnt[j]; a[j] = i; head[j] = false;}
		else {
			cnt[i] += cnt[j];
			a[j] = i;
			head[j] = false;
			sz[i]++;
		}
	}
}
 

void solve() {
	init();
	int n, m;
	cin >> n >> m;
	pair<long long, int> vc[MAX];
	for (int i = 1; i <= n; i++) {
		long long c;
		cin >> c;
		vc[i] = make_pair(c, i);
	}
	sort(vc + 1, vc + n + 1);
	vector<pair<long long, pair<int, int> > > w;
	for (int i = 2; i <= n; i++) {
		long long currw = vc[1].first + vc[i].first;
		w.push_back(make_pair(currw, make_pair(vc[1].second, vc[i].second)));
	}
	for (int i = 0; i < m; i++) {
		int pp, qq;
		long long rr;
		cin >> pp >> qq >> rr;
		w.push_back(make_pair(rr, make_pair(qq, pp)));
	}
	sort(w.begin(), w.end());
	int ok = 1;
	long long res = 0;
	for (auto p : w) {
		if (!connected(p.second.first, p.second.second)) {
			ok++;
			join(p.second.first, p.second.second);
			res += p.first;
		}
		if (ok == n) {
			break;
		}
	}
	cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}