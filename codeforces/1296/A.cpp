#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= 2;
    }
    if (a[0] == 0) {
        for (int i = 1; i < n; i++) {
            if (a[i] == 1) {cout << "YES"; return;}
        }
        cout << "NO"; return;
    }
    else if ((a[0] == 1) && (n % 2 == 0)) {
        for (int i = 1; i < n; i++) {
            if (a[i] == 0) {cout << "YES"; return;}
        }
        cout << "NO"; return;
    }
    else { cout << "YES"; return;}
}

int main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        solve();
        cout << endl;
    }
}
