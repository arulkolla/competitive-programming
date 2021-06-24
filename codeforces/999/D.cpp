#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, m;
	cin >> n >> m;
	long long a[n + 7], cnt[m + 7], pref[m + 7];
	vector<int> someone[m + 7];
	for (int i = 0; i < m; i++) {
		cnt[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i] % m]++;
		someone[a[i] % m].push_back(i);
	}
	for (int i = 0; i < m; i++) {
		pref[i] = cnt[i] - n / m;
		if (i > 0) {pref[i] += pref[i - 1];}
	}
	long long mn = MOD, pos = -1;
	for (int i = 0; i < m; i++) {
		if (pref[i] < mn) {
			mn = pref[i];
			pos = i + 1;
		}
	}
	assert(pos != -1);
	long long res = 0, bef = 0, now, curr;
	queue<pair<int, int> > train;
	for (int i = 0; i < m; i++) {
		curr = (pos + i) % m;
		now = cnt[curr] - n / m;
		bef += now;
		res += bef;
		if (now > 0) {
			// add things to train
			for (int j = 0; j < now; j++) {
				train.push(make_pair(someone[curr][j], i));
			}
		}
		else if (now < 0) {
			// remove things from train
			for (int j = 0; j < -now; j++) {
				pair<int, int> passenger = train.front();
				train.pop();
				a[passenger.first] += i - passenger.second;
			}
		}
	}
	cout << res << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}