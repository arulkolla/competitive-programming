#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[n + 7], b[n + 7], cnt[n + 7];
	for (int i = 1; i <= n; i++) {
		cnt[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	vector<pair<int, int> > va, vb;
	int curr = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i - 1]) {curr++;}
		else {va.emplace_back(a[i - 1], curr); curr = 1;}
	}
	va.emplace_back(a[n - 1], curr);
	curr = 1;
	for (int i = 1; i < n; i++) {
		if (b[i] == b[i - 1]) {curr++;}
		else {vb.emplace_back(b[i - 1], curr); curr = 1;}
	}
	vb.emplace_back(b[n - 1], curr);
	
	int pt = 0;
	for (int i = 0; i < vb.size(); i++) {
		while (pt < (int)va.size()) {
			cnt[va[pt].first] += va[pt].second;
			if (va[pt].first != vb[i].first) {pt++; continue;}
			if (cnt[va[pt].first] >= vb[i].second) {
				cnt[va[pt].first] -= vb[i].second;
				pt++;
				break;
			}
			else {pt++;}
		}
		if (pt == va.size() && i != vb.size() - 1) {cout << "NO\n"; return;}
	}

	cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}