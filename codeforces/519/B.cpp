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
    int n;
    cin >> n;
    int arr1[n], arr2[n-1], arr3[n-2];
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    for (int i = 0; i < n-1; i++) {
        cin >> arr2[i];
    }
    for (int i = 0; i < n-2; i++) {
        cin >> arr3[i];
    }
    sort(arr1, arr1 + n); sort(arr2, arr2 + n - 1); sort(arr3, arr3 + n - 2);
    bool a1 = true, a2 = true;
    for (int i = 0; i < n-1; i++) {
        if (arr1[i] != arr2[i]) {cout << arr1[i]; a1 = false; break;}
    }
    if (a1) {cout << arr1[n-1];}
    cout << endl;
    for (int i = 0; i < n-2; i++) {
        if (arr2[i] != arr3[i]) {cout << arr2[i]; a2 = false; break;}
    }
    if (a2) {cout << arr2[n-2];}
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