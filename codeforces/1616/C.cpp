#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;
const double EPS = 1e-2;

void solve() {
	int n;
	cin >> n;
	long long a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n <= 2) {cout << 0 << '\n'; return;}
	set<double> ds;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ds.insert((double)(a[j] - a[i]) / (j - i));
		}
	}
	int mx = 1;
	for (double d : ds) {
		vector<double> v;
		for (int i = 0; i < n; i++) {
			v.push_back(a[i] - d * i);
		}
		sort(v.begin(), v.end());
		int curr = 1, mxx = 1;
		double el = v[0];
		for (int i = 1; i < v.size(); i++) {
			if (v[i] - el <= EPS) {curr++;}
			else {mxx = max(mxx, curr); el = v[i]; curr = 1;}
		}
		mxx = max(mxx, curr);
		
		mx = max(mx, mxx);
	}
	cout << n - mx << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}