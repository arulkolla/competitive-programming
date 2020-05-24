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
    int a[n];
    cin >> a[0];
    int count = 1;
    vector<int> results;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            count++;
            results.push_back(a[i-1]);
        }
    }
    results.push_back(a[n-1]);
    cout << count << endl;
    for (int i : results) {
        cout << i << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve(); cout << endl;}
    solve();
}