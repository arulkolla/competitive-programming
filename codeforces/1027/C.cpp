
// Problem: C. Minimum Value Rectangle
// Contest: Codeforces - Educational Codeforces Round 49 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1027/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 10007;
const int MOD = 1000000007;

bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
	return ((a.first * a.first + a.second * a.second) * b.first * b.second) < ((b.first * b.first + b.second * b.second) * a.first * a.second);
}

void solve() {
	int n;
	cin >> n;
	int cnt[MAX] = {}, k;
	vector<int> good;
	for (int i = 0; i < n; i++) {
		cin >> k;
		cnt[k]++;
		if (cnt[k] == 2) {good.push_back(k);}
		if (cnt[k] == 4) {good.push_back(k);}
	}
	sort(good.begin(), good.end());
	vector<pair<long long, long long> > v;
	for (int i = 0; i < good.size() - 1; i++) {
		v.push_back(make_pair(good[i], good[i + 1]));
	}
	sort(v.begin(), v.end(), cmp);
	cout << v[0].first << " " << v[0].second << " " << v[0].first << " " << v[0].second << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}