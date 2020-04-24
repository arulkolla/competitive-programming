#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    int n, m, press = 0;
    cin >> n >> m;
    if (n >= m) {cout << n-m; return;}
    while (n != m) {
        if (n < m) {
            if (m % 2 == 0) {
                press++;
                m /= 2;
            }
            else {
                press++;
                m += 1;
            }
        }
        else {
            press++;
            m += 1;
        }
    }
    cout << press;
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