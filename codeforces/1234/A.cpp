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
    int n;
    cin >> n;
    unsigned long long sum = 0, temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        sum += temp;
    }
    if (sum % n) {
        cout << sum / n + 1;
    }
    else {
        cout << sum / n;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve(); cout << endl;}
//    solve();
}