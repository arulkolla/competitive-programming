#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int res = 0;
	// length 1
	res += n;
	// length 2
	res += n - 1;
	// length 3
	for (int i = 0; i < n - 2; i++) {
		if ((a[i+1] > a[i] && a[i+1] > a[i+2]) || (a[i+1] < a[i] && a[i+1] < a[i+2])) {res++;}
	}
	// length 4
	for (int i = 0; i < n - 3; i++) {
		if ((a[i+1] > a[i] && a[i+1] > a[i+3] && a[i+2] < a[i] && a[i+2] < a[i+3]) || 
			(a[i+2] > a[i] && a[i+2] > a[i+3] && a[i+1] < a[i] && a[i+1] < a[i+3])) {res++;}	
	}
	cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}