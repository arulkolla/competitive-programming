#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n % 4 != 0) {cout << "NO"; return;}
    int odd = 1, even = 2, osum = 0, esum = 0, arr[n];
    for (int i = 0; i < n/2 - 1; i++) {
        arr[i] = even;
        arr[i+n/2] = odd;
        osum += odd; esum += even;
        odd += 2; even += 2;
    }
    arr[n/2 - 1] = even;
    esum += even;
    arr[n-1] = esum - osum;
    cout << "YES" << endl;
    for (int k : arr) {
        cout << k << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int i = 1; i <= tt; i++) {
        solve();
        cout << endl;
    }
    //solve();
}