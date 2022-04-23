#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

vector<int> solve(vector<int> a) {
	int n = a.size();
	vector<pair<int, int> > v, w;
	for (int i = 0; i < n; i++) {
		v.emplace_back(a[i], i);
		w.emplace_back(a[i], i);
	}
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());
	int curr = 1, mx = 1;
	for (int i = 1; i < n; i++) {
		if (v[i].first == v[i - 1].first) {curr++;}
		else {mx = max(mx, curr); curr = 1;}
	}
	mx = max(mx, curr);
	rotate(v.begin(), v.begin() + n - mx, v.end());
	vector<int> t(n);
	for (int i = 0; i < n; i++) {t[i] = 0;}
	for (int i = 0; i < n; i++) {
		t[w[i].second] = v[i].first;
	}
	return t;
}

void solve() {
	int n;
	cin >> n;
	int a[n + 7];
	int mn = MOD, mx = -MOD;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
	}
	if (mn == mx) {
		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}
	int cnt[n + 7];
	for (int i = 1; i <= n; i++) {
		cnt[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		cnt[a[i]]++;
	}
	int val = MOD;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] > n / 2) {val = i;}
	}
	if (val == MOD) {
		vector<int> aa;
		for (int i = 0; i < n; i++) {
			aa.push_back(a[i]);
		}
		vector<int> v = solve(aa);
		for (int i = 0; i < n; i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}
	
	int tot = n - cnt[val];
	vector<int> aa;
	int pos[n + 7], taken = 0, curr = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != val) {
			aa.push_back(a[i]);
			pos[curr] = i;
			curr++;
		}
		else {
			if (taken < tot) {
				aa.push_back(a[i]);
				pos[curr] = i;
				curr++;
				taken++;
			}
		}
	}
	int res[n + 7];
	for (int i = 0; i < n; i++) {res[i] = a[i];}
	vector<int> v = solve(aa);
	for (int i = 0; i < v.size(); i++) {
		res[pos[i]] = v[i]; 
	}
	for (int i = 0; i < n; i++) {cout << res[i] << ' ';}
	cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}