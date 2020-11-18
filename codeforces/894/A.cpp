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

const int MAX = 100007;
const int MOD = 1000000007;

void solve() {
    string s;
    cin >> s;
    int q = 0, a = 0, res = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'Q') {
            q++;
            if (q > 1) {res += a;}    
        }
        else if (s[i] == 'A') {a += q;}
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("sample.in", "r", stdin); freopen("sample.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}