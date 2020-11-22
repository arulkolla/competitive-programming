
// Problem: C. Polo the Penguin and XOR operation
// Contest: Codeforces - Codeforces Round #177 (Div. 1)
// URL: https://codeforces.com/contest/288/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long pow2[20] = {1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535,131071,262143,524287,1048575};

void solve() {
	long long n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i <= n; i++) {v.push_back(i);}
	long long mx = n;
	for (int i = 19; i >= 0; i--) {
		if (pow2[i] >= mx) {
			long long cnt = 0;
			while (mx > pow2[i] / 2) {
				swap(v[mx], v[pow2[i] - mx]);
				cnt++;
				mx--;
			}
			mx -= cnt;
		}
	}

	cout << n * n + n << endl;
	for (int i : v) {
		cout << i << " ";
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}