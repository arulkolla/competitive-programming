#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	vector<int> a;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	
	reverse(a.begin(), a.end());
	bool nzero = false;
	int nind;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] > 0) {nzero = true; nind = i; break;}
	}
	if (nzero && a[nind] > 1) {cout << -1; return;}
	if (!nzero) {cout << 0; return;}
	
	vector<pair<int, int> > v;
	int lasth = n;
	stack<int> free1, free2, free3;
	int last1, last2, last3;
	int minh = MOD;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == 0) {
			continue;
		}
		else if (a[i] == 1) {
			v.emplace_back(lasth, n - i);
			free1.push(lasth);
			minh = min(minh, lasth);
			lasth--;
			last1 = n - i;
		}
		else if (a[i] == 2) {
			if (free1.empty()) {cout << -1 << endl; return;}
			v.emplace_back(free1.top(), n - i);
			free2.push(free1.top());
			minh = min(minh, free1.top());
			free1.pop();
			last2 = n - i;
		}
		else {
			if (free1.empty() && free2.empty() && free3.empty()) {cout << -1 << endl; return;}
			if (!free3.empty()) {
				v.emplace_back(minh - 1, n - i);
				v.emplace_back(minh - 1, last3);
				free3.pop();
			}
			else if (!free2.empty()) {
				v.emplace_back(minh - 1, n - i);
				v.emplace_back(minh - 1, last2);
				free2.pop();
			}
			else if (!free1.empty()) {
				v.emplace_back(minh - 1, n - i);
				v.emplace_back(minh - 1, last1);
				free1.pop();
			}
			lasth--;
			free3.push(v[v.size() - 1].first);
			minh = min(minh, v[v.size() - 1].first);
			last3 = n - i;
		}
	}
	cout << v.size() << '\n';
	for (auto p : v) {
		cout << p.first << ' ' << p.second << '\n';
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}