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

void solve() {
  map<pair<pair<long long, long long>, pair<long long, long long> >, long long> m;
  long long x = 0, y = 0;
  long long ans = 0;
  string s;
  cin >> s;

  for (long long int i = 0; i < (long long) s.size(); i++) {
    long long xd = x, yd = y;
    if (s[i] == 'N') y++;
    if (s[i] == 'S') y--;
    if (s[i] == 'E') x++;
    if (s[i] == 'W') x--;
    if(m[{{x, y}, {xd, yd}}] == 1) {ans += 1;}
    else {ans += 5;}
    m[{{x, y}, {xd, yd}}] = 1;
    m[{{xd, yd}, {x, y}}] = 1;
  }
  cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int i = 1; i <= tt; i++) {
        solve();
        cout << endl;
    }
//    solve();
}
