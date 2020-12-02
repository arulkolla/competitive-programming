
// Problem: C - H and V
// Contest: AtCoder - AtCoder Beginner Contest 173
// URL: https://atcoder.jp/contests/abc173/tasks/abc173_c
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int h, w, k;
	cin >> h >> w >> k;
	char c[h + 7][w + 7];
	int tot = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> c[i][j];
			if (c[i][j] == '#') {tot++;}
		}
	}
	int res = 0;
	for (int i = 1; i <= (1 << (h + w)); i++) {
		int now = i, cnt = 1;
		set<pair<int, int> > s;
		while (now > 0) {
			if (now & 1) {
				if (cnt <= h) {
					//check row
					for (int i = 0; i < w; i++) {
						if (c[cnt - 1][i] == '#') {
							s.insert(make_pair(cnt - 1, i));
						}
					}
				}
				else {
					//check column
					for (int i = 0; i < h; i++) {
						if (c[i][cnt - h - 1] == '#') {
							s.insert(make_pair(i, cnt - h - 1));
						}
					}
				}
			}
			now >>= 1;
			cnt++;
		}
		if (tot - s.size() == k) {res++;}
	}
	cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}