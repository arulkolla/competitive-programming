
// Problem: D. Even-Odd Game
// Contest: Codeforces - Codeforces Round #693 (Div. 3)
// URL: https://codeforces.com/contest/1472/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	priority_queue<long long> odd, even;
	long long odds = 0, evens = 0;
	for (int i = 0; i < n; i++) {
		long long k;
		cin >> k;
		if (k % 2) {odd.push(k); odds += k;}
		else {even.push(k); evens += k;}
	}
	long long a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			// Alice
			if (!even.empty() && !odd.empty()) {
				if (even.top() > odd.top()) {a += even.top(); even.pop();}
				else if (even.top() < odd.top()) {odd.pop();}
			}
			else if (!even.empty()) {
				a += even.top(); even.pop();
			}
			else {
				odd.pop();
			}
		}
		else {
			// Bob
			if (!even.empty() && !odd.empty()) {
				if (even.top() < odd.top()) {b += odd.top(); odd.pop();}
				else if (even.top() > odd.top()) {even.pop();}
			}
			else if (!even.empty()) {
				even.pop();
			}
			else {
				b += odd.top(); odd.pop();
			}
		}
	}
	if (a > b) {cout << "Alice";}
	else if (b > a) {cout << "Bob";}
	else {cout << "Tie";}
	cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}