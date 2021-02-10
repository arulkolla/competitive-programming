// Problem: G. Path Queries
// Contest: Codeforces - Codeforces Round #582 (Div. 3)
// URL: https://codeforces.com/contest/1213/problem/G
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

int a[MAX], sz[MAX], cnt[MAX];

long long res = 0;
 
long long f(int n) {
    return ((n * 1LL * (n - 1)) / 2);
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
	    res -= f(cnt[i]);
		res -= f(cnt[j]);
		res += f(cnt[i] + cnt[j]);
		if (sz[i] < sz[j]) {
		    cnt[j] += cnt[i]; a[i] = j;
		}
		else if (
		    sz[i] > sz[j]) {cnt[i] += cnt[j]; a[j] = i;
		}
		else {
			cnt[i] += cnt[j];
			a[j] = i;
			sz[i]++;
		}
	}
}
 
void solve() {
	int v, q;
	cin >> v >> q;
	for (int i = 1; i <= v; i++) {
		a[i] = i;
		sz[i] = 0;
		cnt[i] = 1;
	}
	
	pair<int, pair<int, int> > p[v + 7];
	for (int i = 0; i < v - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		p[i] = make_pair(c, make_pair(a, b));
	}
	sort(p, p + v - 1);
	
	int curr = 1;
	int ans[MAX] = {};
	for (int i = 0; i < v - 1; i++) {
	    while (curr < p[i].first) {
	        ans[curr] = res;
	        curr++;
	    }
	    if (p[i].first == curr) {
	        join(p[i].second.first, p[i].second.second);
	    }
	}
	for (int i = 0; i < q; i++) {
	    int x;
	    cin >> x;
	    if (x >= curr) {cout << f(v) << ' ';}
	    else {cout << ans[x] << ' ';}
	}
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}