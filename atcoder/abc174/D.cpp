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

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    char c[MAX];
    long long count = 0;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        if (c[i] == 'R') {count++;}
    }
    long long res = count;
    for (int i = 0; i < count; i++) {
        if (c[i] == 'R') {res--;}
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("rental.in", "r", stdin); freopen("rental.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve(); cout << endl;}
    solve();
}
