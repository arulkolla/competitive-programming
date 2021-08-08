#include <bits/stdc++.h>

using namespace std;

const int MAX = 27;
const int MOD = 1000000007;

int a[MAX], sz[MAX], cnt[MAX];
bool head[MAX];
vector<string> root[MAX];
 
int find(int p) {
	while (p != a[p]) {
		a[p] = a[a[p]];
		p = a[p];
	}
	return p;
}
 
bool connected(int p, int q) {
	return find(p) == find(q);
}
 
void join(int p, int q) {
	int i = find(p);
	int j = find(q);
	if (i != j) {
		if (sz[i] < sz[j]) {
			cnt[j] += cnt[i]; 
			a[i] = j; 
			head[i] = false;
			for (string s : root[i]) {
				root[j].push_back(s);
			}
		}
		else if (sz[i] > sz[j]) {
			cnt[i] += cnt[j]; 
			a[j] = i; 
			head[j] = false;
			for (string s : root[j]) {
				root[i].push_back(s);
			}
		}
		else {
			cnt[i] += cnt[j];
			a[j] = i;
			head[j] = false;
			sz[i]++;
			for (string s : root[j]) {
				root[i].push_back(s);
			}
		}
	}
}

void clear() {
	for (int i = 0; i < MAX; i++) {
		a[i] = i;
		sz[i] = 0;
		cnt[i] = 1;
		head[i] = true;
	}
}

void solve() {
	clear();
	int n;
	cin >> n;
	string s[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		bool vis[MAX] = {};
		for (char c : s[i]) {
			if (vis[(int)c - (int)'a']) {cout << "NO" << endl; return;}
			else {vis[(int)c - (int)'a'] = true;}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < s[i].size(); j++) {
			join((int)s[i][0] - (int)'a', (int)s[i][j] - (int)'a');
		}
		root[find((int)s[i][0] - (int)'a')].push_back(s[i]);
	}
	vector<string> res;
	for (int i = 0; i < 26; i++) {
		if (head[i] && !root[i].empty()) {
			int to[MAX];
			int from[MAX];
			set<int> seen;
			for (int i = 0; i < MAX; i++) {
				to[i] = -1;
				from[i] = -1;
			}
			for (string ss : root[i]) {
				for (int i = 0; i < ss.size() - 1; i++) {
					if (to[(int)ss[i] - (int)'a'] == -1 ||to[(int)ss[i] - (int)'a'] == (int)ss[i + 1] - (int)'a') {
						to[(int)ss[i] - (int)'a'] = (int)ss[i + 1] - (int)'a';
						from[(int)ss[i + 1] - (int)'a'] = (int)ss[i] - (int)'a';
					}
					else {cout << "NO" << endl; return;}
					seen.insert((int)ss[i] - (int)'a');
					seen.insert((int)ss[i + 1] - (int)'a');
				}
			}
			string rn = "";
			if (!seen.empty()) {
				int head = -1;
				for (int i : seen) {
					if (from[i] == -1) {
						if (head == -1) {head = i;}
						else {cout << "NO" << endl; return;}
					}
				}
				if (head == -1) {cout << "NO" << endl; return;}
				int curr = head;
				bool vis[MAX] = {};
				while (curr != -1) {
					if (!vis[curr]) {
						rn += (char)((int)'a' + curr);
						vis[curr] = true;
						curr = to[curr];
					}
					else {cout << "NO" << endl; return;}
				}
			}
			else {
				for (string ss : root[i]) {
					rn += ss;
				}	
			}
			res.push_back(rn);
		}
	}
	for (string ss : res) {
		bool vis[MAX] = {};
		for (char c : ss) {
			if (vis[(int)c - (int)'a']) {cout << "NO" << endl; return;}
			else {vis[(int)c - (int)'a'] = true;}
		}
	}
	sort(res.begin(), res.end());
	for (string ss : res) {
		cout << ss;
	}
	cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}