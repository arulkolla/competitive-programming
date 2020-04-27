#define ull unsigned long long

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
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        if (n % 10 == 0) {n /= 10;}
        else {n -= 1;}
    }
    cout << n;
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
