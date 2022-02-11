#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	string s;
	cin >> s;
    if (s.length() == 1) {
    	cout << (s[0] == 'X' || s[0] == '_' || s[0] == '0');
    	return;
    }
    int ans = 0;
    for (int x = 0; x <= 9; x++){
        string t = s;
        for (int i = 0; i < t.length(); i++) {if(t[i] == 'X') {t[i] = '0' + x;}}
        if (t[0] == '0') {continue;}
        string last = t.substr(t.length() - 2, 2);
        int cnt = 0;
        for (string p : (t.length() > 2 ? vector<string>{"00", "25", "50", "75"} : vector<string>{"25", "50", "75"})) {
            if((last[0] == p[0] || last[0] == '_') && (last[1] == p[1] || last[1] == '_')) cnt++;
        }
        for(int i = 0; i < t.length() - 2; ++i){
            if(t[i] == '_') cnt *= 10 - (i == 0);
        }
        ans += cnt;
        if (s == t) {break;}
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}