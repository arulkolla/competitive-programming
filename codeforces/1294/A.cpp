#include <algorithm>
#include <cassert>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void solve() {
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    if ((a+b+c+n)%3 != 0) {cout << "NO"; return;}
    int k = max(max(a, b), c);
    int sum = k-a+k-b+k-c;
    if ((n-sum)>=0 && ((n-sum)%3 == 0)) {cout << "YES"; return;}
    cout << "NO";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    for (int i = 1; i <= tt; i++) {
        solve();
        cout << endl;
    }
    //solve();
}