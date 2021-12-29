#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;
const long double EPS = 1e-3;

void solve() {
	int n;
	cin >> n;
	long long a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n <= 2) {cout << 0 << '\n'; return;}
	vector<long double> ds;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ds.push_back((long double)(a[j] - a[i]) / (j - i));
		}
	}
	cout << fixed << setprecision(5);
	int mx = 1;
	for (long double d : ds) {
		vector<long double> v;
		for (int i = 0; i < n; i++) {
			v.push_back(a[i] - d * i);
		}
		sort(v.begin(), v.end());
		int curr = 1;
		long double el = v[0];
		vector<int> szs;
		for (int i = 1; i < v.size(); i++) {
			if (v[i] - el <= EPS) {curr++;}
			else {szs.push_back(curr); el = v[i]; curr = 1;}
		}
		szs.push_back(curr);
		mx = max(mx, *max_element(szs.begin(), szs.end()));
	}
	cout << n - mx << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}