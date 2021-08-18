#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long f(long long r, long long c) {
	if (r < c) {return (c - 1) * (c - 1) + r;}
	else {return r * r - c + 1;}
}

void solve() {
	long long k;
	cin >> k;
	long long mx;
	for (long long i = 1; i <= 100000; i++) {
		if ((i + 1) * (i + 1) > k) {mx = i; break;}
	}
	long long tempc = (mx + 1) * (mx + 1) - k + 1;
	if (mx + 1 >= tempc) {
		cout << mx + 1 << ' ' << tempc << endl;
	}
	else if (k != mx * mx) {
		cout << k - (mx * mx) << ' ' << mx + 1 << endl; 
	}
	else {
		cout << mx << ' ' << 1 << endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}