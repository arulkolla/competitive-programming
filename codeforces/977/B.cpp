#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m = -1;
    string s, rs;
    map<string, int> mp;
    cin >> n;
    cin >> s;
    for (int i = 0; i < s.size() - 1; i++) {
        mp[s.substr(i,2)]++;
    }
    for(auto&q : mp) {
        if(q.second > m) {
            rs = q.first;
            m = q.second;
        }
    }
    cout << rs;
    return 0;
}