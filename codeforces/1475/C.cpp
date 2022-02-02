#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long nC2(long long n) {
	return (n * (n - 1)) / 2;
}

void solve() {
	int a, b, k;
	cin >> a >> b >> k;
	long long bcnt[a + 7], gcnt[b + 7];
	for (int i = 1; i <= a; i++) {bcnt[i] = 0;}
	for (int i = 1; i <= b; i++) {gcnt[i] = 0;}
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		bcnt[x]++;
	}
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		gcnt[x]++;
	}
	long long res = nC2((long long)k);
	for (int i = 1; i <= a; i++) {
		res -= nC2(bcnt[i]);
		// cout <<bcnt[i] << ' ';
	}
	for (int i = 1; i <= b; i++) {
		res -= nC2(gcnt[i]);
		// cout <<gcnt[i] << ' ';
	}
	cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}