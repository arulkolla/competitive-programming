#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int r, g, b;
	cin >> r >> g >> b;
	vector<long long> R, G, B;
	R.push_back(-1);
	B.push_back(-1);
	G.push_back(-1);
	long long e;
	for (int i = 0; i < r; i++) {
		cin >> e;
		R.push_back(e);
	}
	for (int i = 0; i < g; i++) {
		cin >> e;
		G.push_back(e);
	}
	for (int i = 0; i < b; i++) {
		cin >> e;
		B.push_back(e);
	}
	sort(R.begin(), R.end());
	sort(B.begin(), B.end());
	sort(G.begin(), G.end());
	long long res = 0;
	int dp[207][207][207];
	for (int i = 0; i < 207; i++) {
		for (int j = 0; j < 207; j++) {
			for (int k = 0; k < 207; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
	function<long long(int, int, int)> f = [&](int ri, int gi, int bi) -> long long {
		int empty = (ri == 0) + (gi == 0) + (bi == 0);
		if (empty >= 2) {dp[ri][gi][bi] = 0ll; return 0;}
		else if (dp[ri][gi][bi] != -1) {return dp[ri][gi][bi];}
		else if (empty == 1) {
			if (ri == 0) {
				long long res = G[gi] * B[bi] + f(ri, gi - 1, bi - 1);
				dp[ri][gi][bi] = res;
				return res;
			}
			else if (gi == 0) {
				long long res = B[bi] * R[ri] + f(ri - 1, gi, bi - 1);
				dp[ri][gi][bi] = res;
				return res;
			}
			else {
				long long res = R[ri] * G[gi] + f(ri - 1, gi - 1, bi);
				dp[ri][gi][bi] = res;
				return res;
			}
		}
		else {
			long long res = max(G[gi] * B[bi] + f(ri, gi - 1, bi - 1), max(B[bi] * R[ri] + f(ri - 1, gi, bi - 1), R[ri] * G[gi] + f(ri - 1, gi - 1, bi)));
			dp[ri][gi][bi] = res;
			return res;
		}
	};
	cout << f(r, g, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}