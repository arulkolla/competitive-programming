#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	if (n <= 1199) {cout << 1200;}
	else if (n <= 1399) {cout << 1400;}
	else if (n <= 1599) {cout << 1600;}
	else if (n <= 1899) {cout << 1900;}
	else if (n <= 2099) {cout << 2100;}
	else if (n <= 2299) {cout << 2300;}
	else if (n <= 2399) {cout << 2400;} 
	else if (n <= 2599) {cout << 2600;}
	else if (n <= 2999) {cout << 3000;}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}