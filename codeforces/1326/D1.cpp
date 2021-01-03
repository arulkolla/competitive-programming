
// Problem: D1. Prefix-Suffix Palindrome (Easy version)
// Contest: Codeforces - Codeforces Global Round 7
// URL: https://codeforces.com/contest/1326/problem/D1
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

bool palindrome(string s) {
	string t = s;
	reverse(t.begin(), t.end());
	return (s == t);
}

string longest(string s) {
	string now, res;
	for (char c : s) {
		now += c;
		if (palindrome(now)) {res = now;}
	}
	return res;
}

void solve() {
	string s;
	cin >> s;
	int n = s.length();
	deque<char> ds;
	for (char c : s) {ds.push_back(c);}
	string ps, rps, news;
	bool done = false;
	for (int i = 0; i < n / 2; i++) {
		if (!done && s[i] == s[n - 1 - i]) {
			ps += ds.front();
			ds.pop_front();
			ds.pop_back();
		}
		else {
			break;
		}
	}
	for (char c : ds) {
		news += c;
	}
	rps = ps;
	reverse(rps.begin(), rps.end());
	string new1, new2, newf;
	new1 = longest(news);
	reverse(news.begin(), news.end());
	new2 = longest(news);
	if (new1.size() >= new2.size()) {newf = new1;}
	else {newf = new2;}
	cout << ps << newf << rps << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}