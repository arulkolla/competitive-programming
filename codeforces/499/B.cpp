#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    string words[3003][2];
    int lengths[3003][2];
    string p, q;
    for (int i = 0; i < m; i++) {
        cin >> p >> q;
        words[i][0] = p; words[i][1] = q;
        lengths[i][0] = p.length(); lengths[i][1] = q.length();
    }
    string s;
    int check;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (words[j][0] == s || words[j][1] == s) {
                check = j;
                break;
            }
        }
        if (lengths[check][0] <= lengths[check][1]) {
            cout << words[check][0] << " ";
        }
        else {
            cout << words[check][1] << " ";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve(); cout << endl;}
    solve();
}