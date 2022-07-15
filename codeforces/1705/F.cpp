#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

string key;

int n, nl, extra, fsofar = 0;
bool done = false;

int doit(string s, string t) {
	int res = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'T' && t[i] == '1') {res++;}
		if (s[i] == 'F' && t[i] == '0') {res++;}
	}
	return res;
}

int send(vector<int> v, bool addt) {
	string s;
	for (int i = 0; i < n; i++) {s += 'F';}
	int tried = 0;
	for (int i : v) {
		if (i - 1 < n) {
			s[i - 1] = 'T';	
		}
		else if (addt) {tried++;}
	}
	cout << s << endl;
	int resp;
	// int resp = doit(s, key);
	cin >> resp;
	if (resp == n) {done = true;}
	resp -= fsofar;
	if (addt) {resp += (extra - tried);}
	return resp;
}

int f(int resp, int tot, int mx, int sz) {
	return (resp + tot - (mx - sz)) / 2;
}

void solve() {
	// cin >> key; n = key.length();
	cin >> n;
	nl = ((n + 12) / 13) * 13, extra = nl - n;
	// cout << nl << ' ' << extra << '\n';
	char fin[n + 14];
	for (int i = 1; i <= n + 13; i++) {fin[i] = 'F';}
	string hhh;
	for (int i = 0; i < n; i++) {hhh += 'F';}
	cout << hhh << endl;
	int respresp;
	// respresp = doit(hhh, key);
	cin >> respresp;
	if (respresp == n) {return;}
	// cout << respresp << '\n';
	for (int i = 1; i <= n; i += 13) {
		// cout << fsofar << '\n';
		// i ... i + 12
		fsofar = 0;
		bool addt = false;
		if (i + 13 > n) {addt = true;}
		vector<int> v;
		for (int j = 0; j < 13; j++) {v.push_back(i + j);}
		int tot = send(v, addt);
		if (done) {return;}
		v.clear();
		// cout << tot << '\n';
		int left = min(n - i + 1, 13);
		fsofar = (respresp + tot - left) / 2;
		// cout << fsofar << '\n';
		tot -= fsofar;
		
		for (int j = 5; j < 10; j++) {v.push_back(i + j);}
		int btot = send(v, addt);
		if (done) {return;}
		btot = f(btot, tot, 13, v.size());
		v.clear();
		
		int a[3], b[3];
		
		v.push_back(i + 2); v.push_back(i + 3); v.push_back(i + 7); v.push_back(i + 8); v.push_back(i + 10);
		a[0] = send(v, addt);
		if (done) {return;}
		a[0] = f(a[0], tot, 13, v.size());
		v.clear();
		v.push_back(i); v.push_back(i + 2); v.push_back(i + 4); v.push_back(i + 5); v.push_back(i + 7); v.push_back(i + 9); v.push_back(i + 11);
		a[1] = send(v, addt);
		if (done) {return;}
		a[1] = f(a[1], tot, 13, v.size());
		v.clear();
		v.push_back(i); v.push_back(i + 3); v.push_back(i + 5); v.push_back(i + 8); v.push_back(i + 12);
		a[2] = send(v, addt);
		if (done) {return;}
		a[2] = f(a[2], tot, 13, v.size());
		v.clear();
		
		v.push_back(i + 2); v.push_back(i + 3); v.push_back(i + 5); v.push_back(i + 6); v.push_back(i + 9);
		b[0] = send(v, addt);
		if (done) {return;}
		b[0] = f(b[0], tot, 13, v.size());
		b[0] -= btot;
		v.clear();
		v.push_back(i); v.push_back(i + 2); v.push_back(i + 4); v.push_back(i + 6); v.push_back(i + 8);
		b[1] = send(v, addt);
		if (done) {return;}
		b[1] = f(b[1], tot, 13, v.size());
		b[1] -= btot;
		v.clear();
		v.push_back(i); v.push_back(i + 3); v.push_back(i + 6); v.push_back(i + 7); v.push_back(i + 9);
		b[2] = send(v, addt);
		if (done) {return;}
		b[2] = f(b[2], tot, 13, v.size());
		b[2] -= btot;
		v.clear();
		
		int xtot = 0;
		int aa[3], bb[3];
		for (int j = 0; j < 3; j++) {
			if ((b[j] + a[j]) % 2 == 1) {
				fin[i + 10 + j] = 'T';
				xtot++;
				a[j]--;
			}
			aa[j] = (a[j] + b[j]) / 2;
			bb[j] = a[j] - aa[j];
		}
		aa[2] -= aa[0];
		bb[2] -= bb[0];
		
		int atot = tot - btot - xtot;
		
		// now solve for atot [i, i + 4] and btot [i + 5, i + 9]
		int xatot = 0, xbtot = 0;
		if ((aa[1] + aa[2]) % 2 == 1) {
			fin[i + 4] = 'T';
			aa[1]--;
			xatot++;
		}
		int ratot = aa[0], latot = atot - ratot - xatot;
		
		if ((aa[1] + aa[2]) / 2 == 1) {
			fin[i] = 'T';
			latot--;
		}
		if (latot == 1) {
			fin[i + 1] = 'T';
		}
		if (aa[1] - ((aa[1] + aa[2]) / 2) == 1) {
			fin[i + 2] = 'T';
			ratot--;
		}
		if (ratot == 1) {
			fin[i + 3] = 'T';
		}
		
		if ((bb[1] + bb[2]) % 2 == 1) {
			fin[i + 9] = 'T';
			bb[1]--;
			xbtot++;
		}
		int rbtot = bb[0], lbtot = btot - rbtot - xbtot;
		
		if ((bb[1] + bb[2]) / 2 == 1) {
			fin[i + 5] = 'T';
			lbtot--;
		}
		if (lbtot == 1) {
			fin[i + 6] = 'T';
		}
		if (bb[1] - ((bb[1] + bb[2]) / 2) == 1) {
			fin[i + 7] = 'T';
			rbtot--;
		}
		if (rbtot == 1) {
			fin[i + 8] = 'T';
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << fin[i];
	}
	cout << endl;
	// int resp;
	// cin >> resp;
	// assert(resp == n);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	solve();
}