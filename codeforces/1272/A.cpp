#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long f(long long a, long long b, long long c) {
	return abs(a - b) + abs(b - c) + abs(c - a);
}

void solve() {
	long long a, b, c;
	cin >> a >> b >> c;
	long long dist = f(a, b, c);
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			for (int k = -1; k <= 1; k++) {
				dist = min(dist, f(a + i, b + j, c + k));
			}
		}
	}
	cout << dist << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}