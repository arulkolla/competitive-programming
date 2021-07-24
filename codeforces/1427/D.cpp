#include <bits/stdc++.h>

using namespace std;

const int MAX = 57;
const int MOD = 1000000007;

int a[MAX];

void f(vector<int> v) {
	int b[MAX];
	for (int i = 1; i < MAX; i++) {
		b[i] = a[i];
	}
	vector<vector<int> > rev;
	int curr = 0;
	for (int i : v) {
		vector<int> now;
		for (int j = 1; j <= i; j++) {
			curr++;
			now.push_back(curr);
		}
		rev.push_back(now);
	}
	reverse(rev.begin(), rev.end());
	int pos = 0;
	for (auto vec : rev) {
		for (int i : vec) {
			pos++;
			a[pos] = b[i];
			// cout << a[pos] << ' ';
		}
	}
	// cout << endl;
}

void solve() {
	int n;
	cin >> n;
	if (n == 1) {cout << 0 << endl; return;}
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<vector<int> > ans;
	int posn;
	for (int i = 1; i <= n; i++) {
		if (a[i] == (n + 1) / 2) {posn = i;}
	}
	if (posn != n) {
		vector<int> curr;
		curr.push_back(posn);
		curr.push_back(n - posn);
		f(curr);
		ans.push_back(curr);
	}
	int len = 1;
	for (int nxt = 1; nxt <= n - 1; nxt++) {
		vector<int> curr;
		bool rt = (nxt % 2 == 1);
		int next = (n + 1) / 2 + (rt ? (nxt + 1) / 2 : -(nxt + 1) / 2);
		if (rt) {
			int pos;
			for (int i = 1; i <= n; i++) {
				if (a[i] == next) {pos = i;}
			}
			if (pos == 1) {
				curr.push_back(n - len);
				curr.push_back(len);
			}
			else {
				curr.push_back(pos - 1);
				curr.push_back(n - len - pos + 1);
				curr.push_back(len);
			}
		}
		else {
			int pos;
			for (int i = 1; i <= n; i++) {
				if (a[i] == next) {pos = i;}
			}
			if (pos == n) {
				curr.push_back(len);
				curr.push_back(n - len);
			}
			else {
				curr.push_back(len);
				curr.push_back(pos - len);
				curr.push_back(n - pos);
			}
		}
		f(curr);
		ans.push_back(curr);
		len++;
	}
	cout << ans.size() << endl;
	for (auto vec : ans) {
		cout << vec.size() << ' ';
		for (int i : vec) {
			cout << i << ' ';
		}
		cout << endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}