#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long binpow(long long a, long long b) {
    a %= MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
        	res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void solve() {
	int n;
	cin >> n;
	int a[n + 7], b[n + 7];
	bool vis[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		vis[i] = false;
	}
	for (int i = n; i < n + 5; i++) {
		vis[i] = false;
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	int g[n + 7];
	for (int i = 0; i < n; i++) {
		g[a[i]] = b[i];
	}
	int curr = 1;
	long long cnt = 0;
	while (curr <= n) {
		if (!vis[curr]) {
			int now = curr;
			while (!vis[now]) {
				vis[now] = true;
				now = g[now];
			}
			cnt++;
		}
		curr++;
	}
	cout << binpow(2ll, cnt) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}