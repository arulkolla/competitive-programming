#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) {return false;}
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {return false;}
    }
    return true;
}

void solve() {
    bool broke = false;
    int n, c;
    cin >> n;
    long long a;
    long double b;
    for (int i = 0; i < n; i++) {
        cin >> a;
        b = (sqrt(a)-floor(sqrt(a)));
        if (b == 0) {
            c = floor(sqrt(a));
            if (isPrime(c)) {cout << "YES" << endl;}
            else {cout << "NO" << endl;}
        }
        else {cout << "NO" << endl;}
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