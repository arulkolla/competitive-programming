#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    int MAX_INT = 100005;
    int i, l, m, n, a[MAX_INT], c[MAX_INT], r[MAX_INT];
    for(cin >> n >> m; i++<n;) {
        cin>>a[i];   
    }
    for(;--i;) {
        r[i]=r[i+1]+!c[a[i]]++;
    }
    for(;m--;cout<<r[l]<<endl) {
        cin>>l;
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
