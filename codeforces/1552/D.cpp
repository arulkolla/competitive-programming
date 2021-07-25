#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int vala;
	set<int> as;
	for (int i = 0; i < n; i++) {
		cin >> vala;
		if (vala != 0) {
			as.insert(abs(vala));
		}
	}
	int m = as.size();
	vector<int> a(as.begin(), as.end());
	sort(a.begin(), a.end());
	if (n > m) {
		cout << "YES" << endl;
		return;
	}
	else if (n == 1 || n == 2) {
		cout << "NO" << endl;
		return;
	}
	else if (n == 3) {
		if (a[0] + a[1] == a[2]) {cout << "YES" << endl;}
		else {cout << "NO" << endl;}
		return;
	}
	else {
		vector<int> v;
		for (int i = 0; i < (1 << m); i++) {
			int curr = i, sum = 0;
			for (int j = 0; j < m; j++) {
				if (curr & 1) {
					sum += a[j];
				}
				curr >>= 1;
			}
			v.push_back(sum);
		}

		for (int i = 0; i < v.size(); i++) {
			for (int j = i + 1; j < v.size(); j++) {
				if ((v[i] == v[j]) && ((i & j) == 0) && (i != 0) && (j != 0)) {
					cout << "YES" << endl;
					return;
				}
			}
		}
		cout << "NO" << endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}