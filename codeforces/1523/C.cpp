#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[n];
	stack<int> s;
	string curr = "";
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		while (true) {
			if (s.empty()) {
				s.push(x);
				break;
			}
			else if (s.top() + 1 == x) {
				s.top()++;
				break;
			}
			else if (x != 1) {
				s.pop();
			}
			else {
				s.push(x);
				break;
			}
		}
		
		vector<int> temp;
		while (!s.empty()) {
			temp.push_back(s.top());
			s.pop();
		}
		reverse(temp.begin(), temp.end());
		for (int i = 0; i < temp.size(); i++) {cout << temp[i] << ".\n"[i == temp.size() - 1];}
		for (int i : temp) {s.push(i);}
	}
	// cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}