#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000007;
const int MOD = 1000000007;

pair<int, int> asum[MAX], bsum[MAX];

void solve() {
	int n;
	cin >> n;
	cout << asum[n].first + asum[n].second << ' ' << bsum[n].first + bsum[n].second << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	asum[0] = make_pair(0, 0);
	bsum[0] = make_pair(0, 0);
	int curr = 0, len = 1, left = 1;
	for (int i = 1; i < MAX; i++) {
		if (curr == 0) {
			if (i % 2 == 1) {
				asum[i] = make_pair(asum[i - 1].first + 1, asum[i - 1].second);
			}
			else {
				asum[i] = make_pair(asum[i - 1].first, asum[i - 1].second + 1);
			}
			bsum[i] = bsum[i - 1];
		}
		else {
			if (i % 2 == 1) {
				bsum[i] = make_pair(bsum[i - 1].first + 1, bsum[i - 1].second);
			}
			else {
				bsum[i] = make_pair(bsum[i - 1].first, bsum[i - 1].second + 1);
			}
			asum[i] = asum[i - 1];
		}
		left--;
		if (left == 0) {
			len++;
			left = len;
			if (len % 2 == 0) {
				curr = 1 - curr;	
			}
		}
	}
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}