#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iomanip>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int w = n % 10;
    if (w == 2 || w == 4 || w == 5 || w == 7 || w == 9) {cout << "hon";}
    else if (w == 0 || w == 1 || w == 6 || w == 8) {cout << "pon";}
    else {cout << "bon";}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve(); cout << endl;}
    solve();
}
