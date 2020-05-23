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

bool isVowel(char c) {
    cout << (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void solve() {
    int x;
    cin >> x;
    if (x % 5 == 0) {
        cout << x/5;
    }
    else {
        cout << x/5 + 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve(); cout << endl;}
    solve();
}