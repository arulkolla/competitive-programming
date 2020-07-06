#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int MAX = 507;
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    int a = 0, w = 0, t = 0, l = 0;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "AC") {a++;}
        if (s == "WA") {w++;}
        if (s == "TLE") {t++;}
        if (s == "RE") {l++;}
    }
    cout << "AC x " << a << endl << "WA x " << w << endl << "TLE x " << t << endl << "RE x " << l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve(); cout << endl;}
    solve();
}