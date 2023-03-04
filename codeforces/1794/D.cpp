#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000007;
const int SZ = 4057;
const int MOD = 998244353;

bool is_prime[MAX];
int fact[MAX], invfact[MAX], inv[MAX];
int dp[SZ][SZ];

int add(int x, int y) {
	return (x + y) % MOD;
}

int sub(int x, int y) {
	return add(x, MOD - y);
}

int mul(int x, int y) {
	return (x * 1ll * y) % MOD;
}

int nCk(int n, int k) {
	if (n < k) {return 0;}
	return mul(fact[n], mul(invfact[k], invfact[n - k]));
}

void solve() {
	int n;
	cin >> n;
	map<int, int> mp;
	for (int i = 0; i < 2 * n; i++) {
		int x;
		cin >> x;
		if (mp.find(x) != mp.end()) {mp[x]++;}
		else {mp[x] = 1;}
	}
	long long res = fact[n];
	vector<int> v;
	v.push_back(0);
	int cnt = 0;
	for (auto p : mp) {
		if (!is_prime[p.first]) {
			res = mul(res, invfact[p.second]);
		}
		else {
			v.push_back(p.second);
			cnt++;
		}
	}
	if (cnt < n) {cout << 0 << '\n'; return;}
	for (int j = 0; j < SZ; j++) {
		if (j == 0) {
			dp[1][j] = invfact[v[1] - 1];
		}
		else if (j == 1) {
			dp[1][j] = invfact[v[1]];
		}
		else {
			dp[1][j] = 0;
		}
	}
	dp[0][0] = 1;
	for (int i = 1; i < v.size(); i++) {
		dp[i][0] = mul(dp[i - 1][0], invfact[v[i] - 1]);
	}
	for (int i = 2; i < v.size(); i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = add(mul(dp[i - 1][j - 1], invfact[v[i]]), mul(dp[i - 1][j], invfact[v[i] - 1]));
		}
	}
	cout << mul(res, dp[cnt][cnt - n]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 0; i < MAX; i++) {
		is_prime[i] = true;
	}
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i < MAX; i++) {
	    if (is_prime[i] && (long long)i * i < MAX) {
	        for (int j = i * i; j <= MAX; j += i) {
	        	is_prime[j] = false;
	        } 
	    }
	}
	inv[1] = 1;
	for(int i = 2; i < MAX; i++) {
		inv[i] = MOD - (long long)(MOD / i) * inv[MOD % i] % MOD;
	} 
	fact[0] = fact[1] = 1;
	invfact[0] = invfact[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fact[i] = ((long long)fact[i - 1] * i) % MOD;
		invfact[i] = ((long long)invfact[i - 1] * inv[i]) % MOD;
	}
	// int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	solve();
}