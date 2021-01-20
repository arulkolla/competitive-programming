
// Problem: A. Cows and Sequence
// Contest: Codeforces - Codeforces Round #174 (Div. 1)
// URL: https://codeforces.com/contest/283/problem/A
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long long sum = 0, last = 1;
	int q;
	cin >> q;
	vector<int> v;
	v.push_back(0);
	for (int i = 0; i < q; i++) {
		int qv;
		cin >> qv;
		if (qv == 1) {
			long long len, val;
			cin >> len >> val;
			sum += min(len, last) * val;
			v[min(len, last) - 1] += val; 
		}
		else if (qv == 2) {
			long long l; 
			cin >> l; 
			v[last - 1] -= l;
			sum += l;
			last++;
			v.push_back(l);
		}
		else {
			sum -= v[last - 1];
			v[last - 2] += v[last - 1];
			last--;
			v.pop_back();
		}
		cout << fixed << setprecision(17) << (long double)(sum) / last << endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}