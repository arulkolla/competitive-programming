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
    unsigned long long int n;
    cin >> n;
    cout << (n * (n*n + 5))/6;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve(); cout << endl;}
    solve();
}