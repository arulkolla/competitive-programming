#include <bits/stdc++.h>

using namespace std;

const int MAX = 100007;
const int MOD = 1000000007;

int top[MAX], bot[MAX];
int tv[MAX], bv[MAX];

pair<int, int> f(int a, int b, int c, int d, int y) {
	int top = a * (y - d) + c * (b - y);
	int bot = b - d;
	if (top % bot == 0) {return make_pair(top / bot, top / bot);}
	else {return make_pair(top / bot, top / bot + 1);}
}

int chk(int x1, int y1, int x2, int y2) {
	int score = 0;
	bool vis[507] = {};
	for (int i = 0; i < 507; i++) {
		vis[i] = false;
	}
	bool bad = false;
	if (y2 < y1) {
		// slope is negative
		pair<int, int> val;
		for (int i = 0; i >= y2; i -= 100) {
			val = f(x1, y1, x2, y2, i);
			if (i % 200 == 0) {
				// bottom
				if (bot[val.first] != -1 && bot[val.second] != -1) {
					if (!vis[bv[val.first]]) {
						score += bot[val.first];
						vis[bv[val.first]] = true;
					}
					else {bad = true;}
				}
				else {bad = true;}
			}
			else {
				// top
				if (top[val.first] != -1 && top[val.second] != -1) {
					if (!vis[tv[val.first]]) {
						score += top[val.first];
						vis[tv[val.first]] = true;
					}
					else {bad = true;}
				}
				else {bad = true;}
			}
		}
	}
	else {
		// slope is positive
		pair<int, int> val;
		for (int i = 100; i <= y2; i += 100) {
			val = f(x1, y1, x2, y2, i);
			if (i % 200 == 0) {
				// bottom
				if (bot[val.first] != -1 && bot[val.second] != -1) {
					if (!vis[bv[val.first]]) {
						score += bot[val.first];
						vis[bv[val.first]] = true;
					}
					else {bad = true;}
				}
				else {bad = true;}
			}
			else {
				// top
				if (top[val.first] != -1 && top[val.second] != -1) {
					if (!vis[tv[val.first]]) {
						score += top[val.first];
						vis[tv[val.first]] = true;
					}
					else {bad = true;}
				}
				else {bad = true;}
			}
		}
	}
	if (bad) {return -1;}
	return score;
}

void solve() {
	int hl, hr, n;
	cin >> hl >> hr >> n;
	for (int i = 0; i < MAX; i++) {top[i] = -1; bot[i] = -1; tv[i] = -1; bv[i] = -1;}
	int score, leftm, rightm;
	char torb;
	for (int i = 0; i < n; i++) {
		cin >> score >> torb >> leftm >> rightm;
		if (torb == 'T') {
			for (int j = leftm; j <= rightm; j++) {
				top[j] = score;
				tv[j] = i;
			}
		}
		else {
			for (int j = leftm; j <= rightm; j++) {
				bot[j] = score;
				bv[j] = i;
			}
		}
	}
	int best = 0;
	for (int c = -10000; c <= 10000; c += 200) {
		// check (0, hl) and (1e5, c - hr)
		best = max(best, chk(0, hl, 100000, c - hr));
		// check (0, hl) and (1e5, c + hr)
		best = max(best, chk(0, hl, 100000, c + hr));
	}
	cout << best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}