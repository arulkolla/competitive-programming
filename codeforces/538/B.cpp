#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    int n;
    vector<string> res;
    cin >> n;
    string s;
    while (n) {
        s = "";
        for (char c : to_string(n)) {
            s.push_back(min('1', c));
        }
        n -= stoi(s);
        res.push_back(s);
    }
    cout << res.size() << endl;
    for (string w : res) {
        cout << w << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    int tt;
//    cin >> tt;
//    for (int i = 1; i <= tt; i++) {
//        solve();
//        cout << endl;
//    }
    solve();
}