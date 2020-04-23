#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n, q[100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }
    if (q[0] % 2 == q[1] % 2) {
        int k = q[0] % 2;
        for (int i = 2; i < n; i++) {
            if (q[i] % 2 != k) {
                cout << i+1; return;
            }
        }
    }
    else {
        if (q[1] % 2 == q[2] % 2) {cout << 1; return;}
        else {cout << 2; return;}
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