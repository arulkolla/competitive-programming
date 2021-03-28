// Problem: B. Card Deck
// Contest: Codeforces - Codeforces Round #704 (Div. 2)
// URL: https://codeforces.com/contest/1492/problem/B
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int curr = n;
	stack<int> now;
	priority_queue<int> rn;
	for (int i = n - 1; i >= 0; i--) {
		now.push(a[i]);
		if (a[i] == curr) {
			int sz = now.size();
			for (int j = 0; j < sz; j++) {
				cout << now.top() << ' ';
				rn.push(now.top());
				now.pop();
			}
			while (true) {
				if (rn.empty()) {break;}
				if (rn.top() == curr) {rn.pop(); curr--;}
				else {break;}
			}
		}
		// cout << endl << "curr: " << curr << endl;
	}
	int sz = now.size();
	for (int j = 0; j < sz; j++) {
		cout << now.top() << ' ';
		now.pop();
	}
	cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}