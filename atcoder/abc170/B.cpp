#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int MAX = 2007;
const int MOD = 1000000007;

void solve() {
    int a, b;
    cin >> a >> b;
    if (b % 2) {cout << "No";}
    else if (b >= 2*a && b <= 4*a) {cout << "Yes";}
    else {cout << "No";}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve(); cout << endl;}
    solve();
}
